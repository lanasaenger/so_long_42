/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:09:48 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/24 17:46:52 by lavinia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/libft/libft.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define TILE_SIZE 64

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
	int				collectibles;
}					t_map;

typedef struct s_textures
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}	t_textures;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player_img;
	int			player_x;
	int			player_y;
	t_map		*map;
	int			moves;
	t_textures	textures;
}	t_game;

int		check_map_characters(t_game *game, int *p, int *c, int *e);
int		check_map_rules(t_game *game);
int		validate_accessibility(t_game *game, char **map_copy);
int		check_map_accessibility(t_game *game);
void	flood_fill(char **map, int y, int x);
char	**free_map_on_fail(char **map, int y);
char	**copy_map(char **map, int height, int width);
int		count_lines(const char *map_file);
int		fill_map(int fd, int lines, char **grid);
t_map	*allocate_map(int lines);
t_map	*load_map(const char *map_file, t_game *game);
void	free_map(char **map, int height);
void	print_move_count(int moves);
void	cleanup_game(t_game *game);
int		init_game(t_game *game, const char *map_path);
int		is_valid_move(t_game *game, int new_x, int new_y);
void	set_player_position(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	move_player(t_game *game, char direction);
int		check_file_exists(const char *path);
void	load_texture(mlx_t *mlx, mlx_image_t **image, const char *path);
void	load_textures(t_game *game);
void	render_tile(t_game *game, int x, int y);
void	render_map(t_game *game);
void	set_game_null(t_game *game);
void	set_map_null(t_game *game);
void	cleanup(t_game *game);
void	collect_item(t_game *game, int x, int y);
void	process_move(t_game *game, int new_x, int new_y);
void	validate_win(t_game *game);
int		count_collectibles(char **grid, int height, int width);
void	finish_level(t_game *game);
void	update_player_position(t_game *game, int new_x, int new_y, char next_tile);
int is_map_rectangular(t_game *game);
int is_valid_map_extension(const char *filename);
#endif