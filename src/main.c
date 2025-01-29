/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:13:19 by lamachad          #+#    #+#             */
/*   Updated: 2025/01/28 17:23:50 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDTH 800
#define HEIGHT 600
#define MOVE_SPEED 5

void render_map(t_game *game)
{
    int x, y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == '1')
                mlx_image_to_window(game->mlx, game->textures.wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map->grid[y][x] == '0')
                mlx_image_to_window(game->mlx, game->textures.floor, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map->grid[y][x] == 'C')
                mlx_image_to_window(game->mlx, game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map->grid[y][x] == 'E')
                mlx_image_to_window(game->mlx, game->textures.exit, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
    if (mlx_image_to_window(game->mlx, game->textures.player, game->x, game->y) < 0)
    {
        write(2, "Erro ao adicionar jogador à janela.\n", 37);
        exit(EXIT_FAILURE);
    }
}


void cleanup_game(t_game *game)
{
    if (game->textures.wall)
        mlx_delete_image(game->mlx, game->textures.wall);
    if (game->textures.floor)
        mlx_delete_image(game->mlx, game->textures.floor);
    if (game->textures.collectible)
        mlx_delete_image(game->mlx, game->textures.collectible);
    if (game->textures.exit)
        mlx_delete_image(game->mlx, game->textures.exit);
    if (game->textures.player)
        mlx_delete_image(game->mlx, game->textures.player);
    if (game->mlx)
        mlx_terminate(game->mlx);
}

int init_game(t_game *game, const char *map_path)
{
    game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
    if (!game->mlx)
    {
        write(2, "Erro: Falha ao inicializar MLX.\n", 33);
        return false;
    }

    // Carrega a textura de fundo antes de tudo
    create_background_with_texture(game, "/nfs/homes/lamachad/so_long/assets/bottom.png");

    // Carrega o mapa
    game->map = load_map(map_path);
    if (!game->map)
    {
        write(2, "Erro: Falha ao carregar mapa.\n", 31);
        return false;
    }

    // Carrega as texturas
    load_textures(game);

    return true;
}
// int init_game(t_game *game, const char *map_file)
// {
//     game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
//     if (!game->mlx)
//         return (write(2, "Erro ao iniciar MLX\n", 20), 0);

//     game->map = load_map(map_file);
//     if (!game->map)
//         return (write(2, "Erro ao carregar o mapa\n", 24), 0);

//     load_textures(game);
//     game->x = TILE_SIZE;
//     game->y = TILE_SIZE;

//     return (1);
// }

int main(void)
{
    t_game game;
    game.x = 0;
    game.y = 0;

    if (!init_game(&game, "./maps/mapa.ber"))
    {
        write(2, "Erro: Falha na inicialização do jogo.\n", 38);
        return EXIT_FAILURE;
    }

    render_map(&game); // Renderiza o mapa corretamente

    // Inicia o loop do MLX
    mlx_key_hook(game.mlx, handle_esc, &game);
    mlx_loop_hook(game.mlx, update, &game);
    mlx_loop(game.mlx);

    cleanup_game(&game);
    
    return EXIT_SUCCESS;
}

