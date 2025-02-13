/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:57:31 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/13 18:58:00 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_exists(const char *path)
{
	if (access(path, F_OK) != -1)
		return (1);
	else
		return (0);
}

void	load_texture(mlx_t *mlx, mlx_image_t **image, const char *path)
{
	mlx_texture_t *texture;

	texture = mlx_load_png(path);
	if (!check_file_exists(path))
	{
		write(2, "Erro: Arquivo de textura não encontrado: ", 41);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	if (!texture)
	{
		write(2, "Erro ao carregar textura: ", 26);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	*image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!(*image))
	{
		write(2, "Erro ao converter textura para imagem: ", 39);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	load_textures(t_game *game)
{
	load_texture(game->mlx, &game->textures.wall, "assets/wall.png");
	load_texture(game->mlx, &game->textures.floor, "assets/bottom.png");
	load_texture(game->mlx, &game->textures.collectible, "assets/collectable.png");
	load_texture(game->mlx, &game->textures.exit, "assets/portal.png");
	load_texture(game->mlx, &game->textures.player, "assets/character2.png");
	if (!(game->textures.player))
	{
    	write(2, "Erro ao carregar a textura do jogador.\n", 39);
    	exit(EXIT_FAILURE);
	}
}


void    render_tile(t_game *game, int x, int y)
{
    if (game->map->grid[y][x] == '1')
        mlx_image_to_window(game->mlx, game->textures.wall, x * TILE_SIZE, y * TILE_SIZE);
    else if (game->map->grid[y][x] == '0')
        mlx_image_to_window(game->mlx, game->textures.floor, x * TILE_SIZE, y * TILE_SIZE);
    else if (game->map->grid[y][x] == 'C')
        mlx_image_to_window(game->mlx, game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
    else if (game->map->grid[y][x] == 'E')
        mlx_image_to_window(game->mlx, game->textures.exit, x * TILE_SIZE, y * TILE_SIZE);
    else if (game->map->grid[y][x] == 'P')
    {
        game->player_x = x * TILE_SIZE;
        game->player_y = y * TILE_SIZE;
    }
}

void    render_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
			mlx_image_to_window(game->mlx, game->textures.floor, x * TILE_SIZE, y * TILE_SIZE);
            render_tile(game, x, y);
            x++;
        }
        y++;
    }
    if (mlx_image_to_window(game->mlx, game->textures.player, game->player_x, game->player_y) < 0)
    {
        write(2, "Erro ao adicionar jogador à janela.\n", 37);
        exit(EXIT_FAILURE);
    }
}	
