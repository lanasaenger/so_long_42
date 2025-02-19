/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:09:48 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/19 15:29:37 by lamachad         ###   ########.fr       */
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

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*player_img;
	int				player_x;
	int				player_y;
	t_map			*map;
	int				moves;
	struct
	{
		mlx_image_t	*wall;
		mlx_image_t	*floor;
		mlx_image_t	*collectible;
		mlx_image_t	*exit;
		mlx_image_t	*player;
	} textures;
}					t_game;

void				update(void *param);
void				move_image(t_game *game, int dx, int dy);
void				key_hook(mlx_key_data_t keydata, void *param);
void				render_map(t_game *game);
void				render_tile(t_game *game, int x, int y);
int					count_lines(const char *map_file);
void				cleanup_game(t_game *game);
int					init_game(t_game *game, const char *map_file);
void				create_background_with_texture(t_game *game,
						const char *file_path);
t_map				*load_map(const char *map_file, t_game *game);
void				set_game_null(t_game *game);
void				load_textures(t_game *game);
void				load_texture(mlx_t *mlx, mlx_image_t **image,
						const char *path);
int					check_file_exists(const char *path);
void				set_map_null(t_game *game);
int					can_move(char **map_grid, int new_x, int new_y);
int					is_valid_move(t_game *game, int new_x, int new_y);
t_map				*allocate_map(int lines);
void				update_player_position(t_game *game, int new_x, int new_y);
void				handle_player_input(t_game *game);
void				set_player_position(t_game *game);
void				move_player(t_game *game, char direction);
void				key_hook(mlx_key_data_t keydata, void *param);
void				collect_item(t_game *game, int x, int y);
void				process_move(t_game *game, int new_x, int new_y);
void				validate_win(t_game *game);
void				finish_level(t_game *game);
int					count_collectibles(char **grid, int height, int width);
void				print_move_count(int moves);
void				flood_fill(char **map, int y, int x);
int					check_map_rules(t_game *game);
int					check_map_accessibility(t_game *game);
void				free_map(char **map, int height);
char				**copy_map(char **map, int height, int width);
void				cleanup(t_game *game);

#endif