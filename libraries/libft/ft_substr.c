/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:14:17 by lamachad          #+#    #+#             */
/*   Updated: 2024/11/11 20:19:27 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
