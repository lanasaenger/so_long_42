/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:02:13 by lamachad          #+#    #+#             */
/*   Updated: 2024/11/11 19:34:06 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (unsigned char)c))
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	else
		return (NULL);
}
