/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:21:03 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/17 00:59:27 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_item(t_game *game, int x, int y)
{
	if (game->map->grid[y][x] == 'C')
	{
		game->map->collectibles--;
		mlx_image_to_window(game->mlx, game->textures.floor, game->player_x,
			game->player_y);
		game->map->grid[y][x] = '0';
		game->player_x = x * TILE_SIZE;
		game->player_y = y * TILE_SIZE;
		mlx_image_to_window(game->mlx, game->textures.player, game->player_x,
			game->player_y);
	}
}

void	process_move(t_game *game, int new_x, int new_y)
{
	if (game->map->grid[new_y][new_x] == 'C')
	{
		collect_item(game, new_x, new_y);
		mlx_image_to_window(game->mlx, game->textures.player, new_x * TILE_SIZE,
			new_y * TILE_SIZE);
	}
	if (game->map->grid[new_y][new_x] == 'E')
	{
		validate_win(game);
		return ;
	}
	game->map->grid[game->player_y][game->player_x] = '0';
	render_tile(game, game->player_x, game->player_y);
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	game->map->grid[new_y][new_x] = 'P';
	mlx_image_to_window(game->mlx, game->textures.player, new_x * TILE_SIZE,
		new_y * TILE_SIZE);
}

void	validate_win(t_game *game)
{
	if (game->map->collectibles > 0)
		return ;
	ft_putstr_fd("\nYou won in ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" moves!\n", 1);
	mlx_close_window(game->mlx);
}

int	count_collectibles(char **grid, int height, int width)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (grid[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	finish_level(t_game *game)
{
	if (game->map->collectibles == 0)
	{
		mlx_close_window(game->mlx);
		exit(0);
	}
}
