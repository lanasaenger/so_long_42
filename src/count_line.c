/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:14:13 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/10 13:47:32 by lavinia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_lines(int fd)
{
    char 	*line;
    int 		count;

	count = 0;
	line = 0;
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	lseek(fd, 0, SEEK_SET); // Retorna o ponteiro do arquivo para o início
	return (count);
}

// Função para preencher o mapa linha por linha usando get_next_line
char	**fill_map(int fd, int lines, char **grid)
{
	if (lines == 0)
	{
		return (grid);
	}
	grid[lines - 1] = get_next_line(fd);
	if (!grid[lines - 1])
	{
		return (NULL);
	}
	return (fill_map(fd, lines - 1, grid));
}

t_map	*load_map(const char *map_file)
{
	int		fd;
	int		lines;
	t_map	*map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		return (perror("Erro ao abrir o arquivo do mapa"), NULL);
	}
	lines = count_lines(fd);
	if (lines <= 0)
	{
		return (close(fd), NULL);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		return (close(fd), NULL);
	}
	map->grid = malloc(sizeof(char *) * (lines + 1));
	if (!map->grid)
	{
		return (free(map), close(fd), NULL);
	}
	if (!fill_map(fd, lines, map->grid))
	{
		while (lines--)
			free(map->grid[lines]);
		return (free(map->grid), free(map), close(fd), NULL);
	}
	close(fd);
	map->height = lines;
	map->width = (map->grid[0] ? ft_strlen(map->grid[0]) - 1 : 0);
	return (map);
}