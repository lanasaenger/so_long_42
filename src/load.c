/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:43 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/26 20:29:24 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(const char *map_file)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (count);
}

int	fill_map(int fd, int lines, char **grid)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		grid[i] = get_next_line(fd);
		if (!grid[i])
			return (0);
		i++;
	}
	grid[i] = NULL;
	return (1);
}

void	free_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

t_map	*allocate_map(int lines)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = malloc(sizeof(char *) * (lines + 1));
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	map->grid[lines] = NULL;
	return (map);
}

t_map	*load_map(const char *map_file, t_game *game)
{
	int		fd;
	t_map	*map;
	int		lines;

	(void)game;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (perror("error opening map file"), NULL);
	lines = count_lines(map_file);
	if (lines <= 0)
		return (close(fd), NULL);
	map = allocate_map(lines);
	if (!map)
		return (close(fd), NULL);
	if (!fill_map(fd, lines, map->grid))
	{
		free_map(map);
		return (close(fd), NULL);
	}
	close(fd);
	map->height = lines;
	map->width = ft_strlen(map->grid[0]) - 1;
	return (map);
}
