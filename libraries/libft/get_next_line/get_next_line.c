/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:20:34 by lamachad          #+#    #+#             */
/*   Updated: 2024/12/02 19:56:52 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*is_error(char *residue)
{
	free(residue);
	return (NULL);
}

static char	*read_line(int fd, char *buffer, char *residue)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	if (!residue)
	{
		residue = ft_strdup("");
		if (!residue)
			return (NULL);
	}
	while (!ft_strchr(residue, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (is_error(residue));
		buffer[bytes_read] = '\0';
		temp = residue;
		residue = ft_strjoin(temp, buffer);
		free(temp);
		if (!residue)
			return (NULL);
	}
	return (residue);
}

static char	*get_line(char *residue)
{
	int		i;
	char	*line;

	i = 0;
	if (!residue[i])
		return (NULL);
	while (residue[i] && residue[i] != '\n')
		i++;
	line = ft_substr(residue, 0, i + 1);
	return (line);
}

static char	*new_residue(char *residue)
{
	int		i;
	char	*temp;

	i = 0;
	while (residue[i] && residue[i] != '\n')
		i++;
	if (!residue[i])
		return (is_error(residue));
	temp = ft_substr(residue, i + 1, ft_strlen(residue) - i);
	free(residue);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*residue;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	residue = read_line(fd, buffer, residue);
	free(buffer);
	if (!residue)
		return (NULL);
	line = get_line(residue);
	residue = new_residue(residue);
	return (line);
}
