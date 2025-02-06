/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:34:17 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/06 18:57:43 by lamachad         ###   ########.fr       */
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

void update(void* param)
{
    t_game* game = (t_game*)param;
    if (!game || !game->mlx || !game->textures.player)
        return;

    // Pegamos a instância da imagem do jogador
    mlx_instance_t *player_instance = &game->textures.player->instances[0];

    // Captura entrada de teclado para movimentação
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        player_instance->y -= MOVE_SPEED;
    if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        player_instance->y += MOVE_SPEED;
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        player_instance->x -= MOVE_SPEED;
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        player_instance->x += MOVE_SPEED;
}

void handle_esc(mlx_key_data_t keydata, void *param)
{
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        t_game *game = (t_game *)param;
        mlx_terminate(game->mlx); // Fecha a janela do MLX
        exit(EXIT_SUCCESS);
    }
}

