/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:34:17 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/11 17:05:11 by lavinia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDTH 800
#define HEIGHT 600
#define MOVE_SPEED 5

// void move_image(t_game *game, int dx, int dy)
// {
//     game->x += dx;
//     game->y += dy;

//     // Limite à direita
//     if (game->x > (int)(WIDTH - game->player_img->width))
//         game->x = (int)(WIDTH - game->player_img->width);

//     // Limite inferior
//     if (game->y > (int)(HEIGHT - game->player_img->height))
//         game->y = (int)(HEIGHT - game->player_img->height);

//     // Limite à esquerda
//     if (game->x < 0)
//         game->x = 0;

//     // Limite superior
//     if (game->y < 0)
//         game->y = 0;

//     mlx_image_to_window(game->mlx, game->player_img, game->x, game->y);
// }

void	update(void *param)
{
	t_game*	game;

	game = param;
	if (!game || !game->mlx || !game->textures.player)
		return ;
	mlx_instance_t *player_instance = &game->textures.player->instances[0];
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		player_instance->y -= MOVE_SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		player_instance->y += MOVE_SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		player_instance->x -= MOVE_SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		player_instance->x += MOVE_SPEED;
}
