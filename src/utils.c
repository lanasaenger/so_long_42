/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:12:30 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/11 17:05:23 by lavinia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// // Verifica se a nova posição contém uma parede ('1')
// int	can_move(char **map_grid, int new_x, int new_y)
// {
// 	if (map_grid[new_y][new_x] == '1')
// 		return (0);
// 	return (1);
// }

// void move_player(char **map_grid, int *player_x, int *player_y, char direction)
// {
//     int new_x = *player_x;
//     int new_y = *player_y;

//     // Atualiza coordenadas com base na direção
//     if (direction == 'W')
//         new_y--; // Move para cima
//     else if (direction == 'A')
//         new_x--; // Move para a esquerda
//     else if (direction == 'S')
//         new_y++; // Move para baixo
//     else if (direction == 'D')
//         new_x++; // Move para a direita

//     // Verifica se a nova posição contém uma parede ('1')
//     if (map_grid[new_y][new_x] != '1')
//     {
//         // Atualiza a posição do jogador se for um local válido
//         *player_x = new_x;
//         *player_y = new_y;
//     }
// }

void	move_player(char **map_grid, int *player_x, int *player_y,
	char direction, int map_width, int map_height)
{
	int	new_x;
	int	new_y;

	new_x = *player_x;
	new_y = *player_y;
	if (direction == 'W')
		new_y--;
	else if (direction == 'A')
		new_x--;
	else if (direction == 'S')
		new_y++;
	else if (direction == 'D')
		new_x++;

	// Verifica se está dentro dos limites do mapa
	if (new_x >= 0 && new_x < map_width && new_y >= 0 && new_y < map_height)
	{
		// Verifica se a posição de destino NÃO é uma parede ('1')
		if (map_grid[new_y][new_x] != '1')
		{
			*player_x = new_x;
			*player_y = new_y;
		}
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			move_player(game->map->grid, &(game->player_x),
				&(game->player_y), 'W', game->map->width, game->map->height);
		else if (keydata.key == MLX_KEY_A)
			move_player(game->map->grid, &(game->player_x),
				&(game->player_y), 'A', game->map->width, game->map->height);
		else if (keydata.key == MLX_KEY_S)
			move_player(game->map->grid, &(game->player_x),
				&(game->player_y), 'S', game->map->width, game->map->height);
		else if (keydata.key == MLX_KEY_D)
			move_player(game->map->grid, &(game->player_x),
				&(game->player_y), 'D', game->map->width, game->map->height);
		else if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
	}
}

// void identify_map_elements(t_game *game)
// {
// 	int x;
// 	int y;

// 	y = 0;
// 	while (y < game->map->height)
// 	{
// 		x = 0;
// 		while (x < game->map->width)
// 		{
// 			if (game->map->grid[y][x] == 'P')
// 			{
// 				game->player_x = x;
// 				game->player_y = y;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }