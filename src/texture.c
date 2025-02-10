/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:08:37 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/10 12:41:19 by lavinia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_exists(const char *path)
{
	if (access(path, F_OK) != -1)
		return (1);
	else
		return (0);
}

void	load_texture(mlx_t *mlx, mlx_image_t **image, const char *path)
{
	mlx_texture_t *texture;

	texture = mlx_load_png(path);
	if (!check_file_exists(path))
	{
		write(2, "Erro: Arquivo de textura não encontrado: ", 41);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	if (!texture)
	{
		write(2, "Erro ao carregar textura: ", 26);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	*image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!(*image))
	{
		write(2, "Erro ao converter textura para imagem: ", 39);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	load_textures(t_game *game)
{
	load_texture(game->mlx, &game->textures.wall, "assets/wall.png");
	load_texture(game->mlx, &game->textures.floor, "assets/bottom.png");
	load_texture(game->mlx, &game->textures.collectible, "assets/collectable.png");
	load_texture(game->mlx, &game->textures.exit, "assets/portal.png");
	load_texture(game->mlx, &game->textures.player, "assets/character.png");
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->y -= 10;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->y += 10;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->x -= 10;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->x += 10;
}

