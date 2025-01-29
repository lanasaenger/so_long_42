/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:31:26 by lamachad          #+#    #+#             */
/*   Updated: 2024/11/11 19:18:32 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 && !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy (str, &s1[start], end - start + 2);
	return (str);
}
