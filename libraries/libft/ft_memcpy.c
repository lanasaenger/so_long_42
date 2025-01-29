/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:18:21 by lamachad          #+#    #+#             */
/*   Updated: 2024/11/11 02:19:16 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main()
{
    char source[] = "Hello, World!";
    char destination[20];

    ft_memcpy(destination, source, ft_strlen(source) + 1);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}*/
