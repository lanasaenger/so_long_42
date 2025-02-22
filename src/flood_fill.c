/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 04:30:46 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/19 19:26:58 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// Preenchimento recursivo para marcar áreas acessíveis
void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
	}
	map[y][x] = 'F';
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x - 1);
	flood_fill(map, y, x + 1);
}



char	**free_map_on_fail(char **map, int y)
{
	while (--y >= 0)
		free(map[y]);
	free(map);
	return (NULL);
}

char	**copy_map(char **map, int height, int width)
{
	char	**new_map;
	int		y;
	int		x;

	new_map = (char **)malloc(sizeof(char *) * height);
	if (!new_map)
		return (NULL);
	y = -1;
	while (++y < height)
	{
		new_map[y] = (char *)malloc(sizeof(char) * (width + 1));
		if (!new_map[y])
			return (free_map_on_fail(new_map, y));
		x = -1;
		while (++x < width)
			new_map[y][x] = map[y][x];
		new_map[y][x] = '\0';
	}
	return (new_map);
}


