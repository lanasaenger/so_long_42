/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:21:09 by lamachad          #+#    #+#             */
/*   Updated: 2025/01/20 18:48:57 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (unsigned char)c))
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		size;
	size_t		i;
	size_t		j;

	if (!s || ft_strlen(s) == 0 || start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	size = ft_strlen(s);
	if ((len + start) >= size)
		len = size - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i < size && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;

	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}
