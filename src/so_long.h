/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:09:48 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/10 12:12:36 by lavinia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "MLX42/MLX42.h"
# include "../libraries/libft/libft.h"
# define TILE_SIZE 64

typedef struct	s_map
{
	char	**grid;
	int		width;
	int		height;
}t_map;

typedef struct	s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player_img;
	int			x; // Posição do jogador
	int			y;
	t_map		*map; // Estrutura que representa o mapa
	struct	
	{
		mlx_image_t	*wall;
		mlx_image_t	*floor;
		mlx_image_t	*collectible;
		mlx_image_t	*exit;
		mlx_image_t	*player;
	} textures;
}	t_game;

void	update(void	*param);
void	move_image(t_game *game, int dx, int dy);
void	handle_esc(mlx_key_data_t keydata, void	*param);
void	key_hook(mlx_key_data_t keydata, void *param);
void	render_map(t_game *game);
void	cleanup_game(t_game *game);
int		init_game(t_game *game, const char *map_file);
void	create_background_with_texture(t_game *game, const char *file_path);
t_map	*load_map(const char *map_file);
void	load_textures(t_game *game);
void	load_texture(mlx_t *mlx, mlx_image_t **image, const char *path);
int		check_file_exists(const char *path);
int		can_move(char **map_grid, int new_x, int new_y);
# endif