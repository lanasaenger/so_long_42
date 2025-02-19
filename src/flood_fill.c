/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 04:30:46 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/19 14:06:18 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// Preenchimento recursivo para marcar áreas acessíveis
void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
	}
	map[y][x] = 'F';
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x - 1);
	flood_fill(map, y, x + 1);
}

// Valida se o mapa possui o número correto de elementos
int	check_map_rules(t_game *game)
{
	int	y;
	int	x;
	int	player_count;
	int	collectible_count;
	int	exit_count;

	y = -1;
	player_count = 0;
	collectible_count = 0;
	exit_count = 0;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->grid[y][x] == 'P')
				player_count++;
			else if (game->map->grid[y][x] == 'C')
				collectible_count++;
			else if (game->map->grid[y][x] == 'E')
				exit_count++;
			else if (game->map->grid[y][x] != '0' && game->map->grid[y][x] != '1')
			{
				ft_putstr_fd("Erro: Mapa contém caracteres inválidos!\n", 2);
				return (0);
			}
		}
		if (game->map->width != x) // Verifica se o mapa é retangular
		{
			ft_putstr_fd("Erro: O mapa não é retangular!\n", 2);
			return (0);
		}
	}
	if (player_count != 1 || collectible_count < 1 || exit_count != 1)
	{
		ft_putstr_fd("Erro: O mapa precisa de 1 jogador, pelo menos 1 coletável e 1 saída!\n", 2);
		return (0);
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
	{
		ft_putstr_fd("Erro: Falha ao copiar o mapa!\n", 2);
		return (0);
	}
	y = game->player_y / TILE_SIZE;
	x = game->player_x / TILE_SIZE;
	flood_fill(map_copy, y, x);
	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if ((game->map->grid[y][x] == 'C' || game->map->grid[y][x] == 'E') && map_copy[y][x] != 'F')
			{
				ft_putstr_fd("Erro: Nem todos os coletáveis ou a saída são acessíveis!\n", 2);
				free_map(map_copy, game->map->height);
				return (0);
			}
		}
	}
	free_map(map_copy, game->map->height);
	return (1);
}

char	**copy_map(char **map, int height, int width)
{
	char	**new_map;
	int		y;
	int		x;

	// Aloca memória para a nova matriz
	new_map = (char **)malloc(sizeof(char *) * height);
	if (!new_map)
		return (NULL);

	// Aloca cada linha
	y = 0;
	while (y < height)
	{
		new_map[y] = (char *)malloc(sizeof(char) * (width + 1)); // +1 para o '\0'
		if (!new_map[y])
		{
			// Se a alocação falhar, libera a memória previamente alocada
			while (--y >= 0)
				free(new_map[y]);
			free(new_map);
			return (NULL);
		}
		// Copia a linha do mapa original para a nova matriz
		x = 0;
		while (x < width)
		{
			new_map[y][x] = map[y][x];
			x++;
		}
		new_map[y][x] = '\0'; // Adiciona o terminador de string
		y++;
	}
	return (new_map);
}

