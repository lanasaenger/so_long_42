/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:08:37 by lamachad          #+#    #+#             */
/*   Updated: 2025/01/30 19:06:19 by lavinia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_file_exists(const char *path)
{
    if (access(path, F_OK) != -1)
        return 1;  // O arquivo existe
    else
        return 0;  // O arquivo não existe
}

void load_texture(mlx_t *mlx, mlx_image_t **image, const char *path)
{
    if (!check_file_exists(path))
    {
        write(2, "Erro: Arquivo de textura não encontrado: ", 41);
        write(2, path, ft_strlen(path));
        write(2, "\n", 1);
        exit(EXIT_FAILURE);
    }
    mlx_texture_t *texture = mlx_load_png(path);
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

void load_textures(t_game *game)
{
    load_texture(game->mlx, &game->textures.wall, "assets/wall.png");
    load_texture(game->mlx, &game->textures.floor, "assets/bottom.png");
    load_texture(game->mlx, &game->textures.collectible, "assets/collectable.png");
    load_texture(game->mlx, &game->textures.exit, "assets/portal.png");
    load_texture(game->mlx, &game->textures.player, "assets/character.png");
}

void create_background_with_texture(t_game *game, const char *file_path)
{
    if (!game || !game->mlx)
    {
        ft_putstr_fd("Erro: MLX não inicializado corretamente.\n", 2);
        exit(EXIT_FAILURE);
    }
    mlx_texture_t *texture = mlx_load_png(file_path);
    if (!texture)
    {
        ft_putstr_fd("Erro: Não foi possível carregar a textura de fundo.\n", 2);
        exit(EXIT_FAILURE);
    }
    mlx_image_t *background = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture); // Já convertemos, podemos deletar a textura
    if (!background)
    {
        ft_putstr_fd("Erro: Não foi possível converter a textura em imagem.\n", 2);
        exit(EXIT_FAILURE);
    }
    // Adiciona a imagem de fundo na janela
    if (mlx_image_to_window(game->mlx, background, 0, 0) < 0)
    {
        ft_putstr_fd("Erro: Não foi possível exibir a imagem na janela.\n", 2);
        exit(EXIT_FAILURE);
    }
}


void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        mlx_terminate(game->mlx);
        exit(EXIT_SUCCESS);
    }
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        game->y -= 10; // Move para cima
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        game->y += 10; // Move para baixo
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        game->x -= 10; // Move para a esquerda
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        game->x += 10; // Move para a direita
}

