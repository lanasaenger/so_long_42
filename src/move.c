/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:34:17 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/13 16:48:09 by lavinia          ###   ########.fr       */
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

// void update(void *param)
// {
//     t_game *game = (t_game *)param;
//     if (!game || !game->mlx || !game->textures.player)
//         return ;
//     mlx_instance_t *player_instance = &game->textures.player->instances[0];
//     int new_x = game->player_x;
//     int new_y = game->player_y;

//     if (mlx_is_key_down(game->mlx, MLX_KEY_W))
//         new_y -= 1;
//     if (mlx_is_key_down(game->mlx, MLX_KEY_S))
//         new_y += 1;
//     if (mlx_is_key_down(game->mlx, MLX_KEY_A))
//         new_x -= 1;
//     if (mlx_is_key_down(game->mlx, MLX_KEY_D))
//         new_x += 1;
//     if (is_valid_move(game, new_x, new_y))
//     {
//         game->player_x = new_x;
//         game->player_y = new_y;
//         player_instance->x = new_x * TILE_SIZE;
//         player_instance->y = new_y * TILE_SIZE;
//     }
// }
