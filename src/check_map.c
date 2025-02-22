/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:19:35 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/19 19:36:25 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_characters(t_game *game, int *p, int *c, int *e)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->grid[y][x] == 'P')
				(*p)++;
			else if (game->map->grid[y][x] == 'C')
				(*c)++;
			else if (game->map->grid[y][x] == 'E')
				(*e)++;
			else if (game->map->grid[y][x] != '0' && game->map->grid[y][x] != '1')
				return (ft_putstr_fd("Erro: Mapa contém caracteres inválidos!\n", 2), 0);
		}
		if (x != game->map->width)
			return (ft_putstr_fd("Erro: O mapa não é retangular!\n", 2), 0);
	}
	return (1);
}

int	check_map_rules(t_game *game)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	if (!check_map_characters(game, &p, &c, &e))
		return (0);
	if (p != 1 || c < 1 || e != 1)
		return (ft_putstr_fd(
				"Erro: O mapa precisa de 1 jogador, pelo menos 1 coletável e 1 saída!\n", 2), 0);
	return (1);
}


int	validate_accessibility(t_game *game, char **map_copy)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if ((game->map->grid[y][x] == 'C' || game->map->grid[y][x] == 'E')
				&& map_copy[y][x] != 'F')
			{
				ft_putstr_fd("Erro: Nem todos os coletáveis ou a saída são acessíveis!\n", 2);
				free_map(map_copy, game->map->height);
				return (0);
			}
		}
	}
	return (1);
}

int	check_map_accessibility(t_game *game)
{
	char	**map_copy;
	int		y;
	int		x;

	map_copy = copy_map(game->map->grid, game->map->height, game->map->width);
	if (!map_copy)
		return (ft_putstr_fd("Erro: Falha ao copiar o mapa!\n", 2), 0);
	y = game->player_y / TILE_SIZE;
	x = game->player_x / TILE_SIZE;
	flood_fill(map_copy, y, x);
	if (!validate_accessibility(game, map_copy))
		return (0);
	free_map(map_copy, game->map->height);
	return (1);
}
