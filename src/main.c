/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:13:19 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/26 19:38:01 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_game(t_game *game)
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
}

int	init_game(t_game *game, const char *map_path)
{
	game->map = load_map(map_path, game);
	if (!game->map)
	{
		write(2, "Erro: Falha ao carregar mapa.\n", 31);
		return (false);
	}
	if (!is_map_closed(game->map))
	{
		free_map(game->map);
		free(game);
		return (0);
	}
	set_player_position(game);
	if (!check_map_rules(game) || !check_map_accessibility(game))
	{
		write(2, "Erro: Mapa inválido.\n", 22);
		free_map(game->map);
		return (false);
	}
	game->mlx = mlx_init(game->map->width * TILE_SIZE, game->map->height
			* TILE_SIZE, "totoro", true);
	if (!game->mlx)
	{
		write(2, "Erro: Falha ao inicializar MLX.\n", 33);
		free_map(game->map);
		return (false);
	}
	load_textures(game);
	game->map->collectibles = count_collectibles(game->map->grid,
			game->map->height, game->map->width);
	return (true);
}

static int	check_args_and_init(t_game **game, int argc, char *map)
{
	if (argc < 2)
	{
		write(2, "Erro: Nenhum arquivo de mapa especificado.\n", 44);
		return (EXIT_FAILURE);
	}
	if (!is_valid_map_extension(map))
	{
		ft_putstr_fd("Erro: O arquivo não tem a extensão .ber\n", 2);
		return (EXIT_FAILURE);
	}
	*game = malloc(sizeof(t_game));
	if (!(*game))
	{
		write(2, "Erro: The game couldn't be initialized\n", 38);
		return (EXIT_FAILURE);
	}
	set_game_null(*game);
	if (!init_game(*game, map))
	{
		write(2, "Erro: Falha na inicialização do jogo.\n", 38);
		free(*game);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (check_args_and_init(&game, argc, argv[1]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	render_map(game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
	cleanup(game);
	return (EXIT_SUCCESS);
}
