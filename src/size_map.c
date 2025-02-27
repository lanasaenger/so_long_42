/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:52 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/26 21:58:25 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_closed(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return (0);
	i = -1;
	while (map->grid[0][++i] && map->grid[map->height - 1][i])
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
		{
			return (write(2, "error: not closed by walls\n", 26), 0);
		}
	}
	i = -1;
	while (++i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (write(2, "error: not closed by walls.\n", 27), 0);
	}
	return (1);
}
