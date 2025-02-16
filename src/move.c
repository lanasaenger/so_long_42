/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:56:28 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/16 02:45:21 by lavinia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (!game || !game->map || !game->map->grid)
		return (0);
	if (new_x < 0 || new_x >= game->map->width
		|| new_y < 0 || new_y >= game->map->height)
		return (0);
	if (game->map->grid[new_y][new_x] == '1')
		return (0);
	return (1);
}

void set_player_position(t_game *game)
{
    int y;

	y = 0;
    while (y < game->map->height)
    {
        int x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == 'P') // 'P' representa o jogador no mapa
            {
                game->player_x = x * TILE_SIZE; // Convertendo para coordenadas de pixels
                game->player_y = y * TILE_SIZE;
                return;
            }
            x++;
        }
        y++;
    }
}

void move_player(t_game *game, char direction)
{
    int new_x;
    int new_y;

    // Coordenada atual do jogador no grid
    new_x = game->player_x / TILE_SIZE;
    new_y = game->player_y / TILE_SIZE;
    if (direction == 'W')
        new_y--;
    else if (direction == 'A')
        new_x--;
    else if (direction == 'S')
        new_y++;
    else if (direction == 'D')
        new_x++;
    if (new_x >= 0 && new_x < game->map->width &&
        new_y >= 0 && new_y < game->map->height)
    {
        if (game->map->grid[new_y][new_x] != '1') 
        {
            mlx_image_to_window(game->mlx, game->textures.floor, game->player_x, game->player_y);
            game->player_x = new_x * TILE_SIZE;
            game->player_y = new_y * TILE_SIZE;
            mlx_image_to_window(game->mlx, game->textures.player, game->player_x, game->player_y);
        }
    }
}

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_W)
            move_player(game, 'W');
        else if (keydata.key == MLX_KEY_A)
            move_player(game, 'A');
        else if (keydata.key == MLX_KEY_S)
            move_player(game, 'S');
        else if (keydata.key == MLX_KEY_D)
            move_player(game, 'D');
        else if (keydata.key == MLX_KEY_ESCAPE)
            mlx_close_window(game->mlx);
    }
}