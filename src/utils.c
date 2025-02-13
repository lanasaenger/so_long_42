/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:12:30 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/13 16:34:43 by lavinia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void update(void *param)
{
    t_game *game = (t_game *)param;
    if (!game || !game->mlx || !game->textures.player)
        return ;
    handle_player_input(game);
}

void handle_player_input(t_game *game)
{
    int new_x = game->player_x;
    int new_y = game->player_y;

    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        new_y--;
    if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        new_y++;
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        new_x--;
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        new_x++;

    if (new_x >= 0 && new_x < game->map->width && new_y >= 0 && new_y < game->map->height)
        update_player_position(game, new_x, new_y);
}

void update_player_position(t_game *game, int new_x, int new_y)
{
    if (game->textures.player->count == 0)
        return ;
    if (game->map->grid[new_y][new_x] != '1')
    {
        game->player_x = new_x;
        game->player_y = new_y;
        game->textures.player->instances[0].x = new_x * TILE_SIZE;
        game->textures.player->instances[0].y = new_y * TILE_SIZE;
    }
}

void	move_player(t_game *game, char dir)
{
	int	new_x = game->player_x / TILE_SIZE;  // Coordenada no grid
	int	new_y = game->player_y / TILE_SIZE;

	if (dir == 'W')
		new_y--;
	else if (dir == 'A')
		new_x--;
	else if (dir == 'S')
		new_y++;
	else if (dir == 'D')
		new_x++;

	// Verifica se a nova posição é válida
	if (new_x >= 0 && new_x < game->map->width && new_y >= 0 && new_y < game->map->height)
	{
		if (is_valid_move(game, new_x, new_y))  // Se o movimento for válido
			update_player_position(game, new_x, new_y);  // Atualiza a posição
	}
}


void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
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
