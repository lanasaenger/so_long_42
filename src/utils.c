/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:25:04 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/19 17:54:11 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_game_null(t_game *game)
{
	game->map = NULL;
	game->moves = 0;
	game->player_x = 0;
	game->player_y = 0;
}

void	set_map_null(t_game *game)
{
	game->map->collectibles = 0;
	game->map->height = 0;
	game->map->width = 0;
	game->map->grid = NULL;
}

void	cleanup(t_game *game)
{
	if (game)
	{
		cleanup_game(game);
		if (game->map)
		{
			if (game->map->grid)
				free_map(game->map->grid, game->map->height);
			free(game->map);
		}
		if (game->mlx)
		{
			mlx_terminate(game->mlx);
		}
		free(game);
	}
}


