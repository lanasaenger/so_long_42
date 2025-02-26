/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:25:04 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/26 12:35:45 by lavinia          ###   ########.fr       */
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
	if (game->map)
		free_map(game->map);
			// free(game->map);
		}
		if (game->mlx)
		{
			mlx_terminate(game->mlx);
		}
		free(game);
	}
}

void free_grid(char **grid, int height)
{
    int i;

    if (!grid)
        return;
    i = 0;
    while (i < height)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}


