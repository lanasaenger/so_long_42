/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:52 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/26 19:36:10 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_closed(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->grid)
		return (0);
	i = 0;
	while (map->grid[0][i] && map->grid[map->height - 1][i])
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
		{
			write(2, "Erro: O mapa não está fechado por paredes.\n", 43);
			return (0);
		}
		i++;
	}
	j = 0;
	while (j < map->height)
	{
		if (map->grid[j][0] != '1' || map->grid[j][map->width - 1] != '1')
		{
			write(2, "Erro: O mapa não está fechado por paredes.\n", 43);
			return (0);
		}
		j++;
	}
	return (1);
}
