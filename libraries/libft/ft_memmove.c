/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:26:23 by lamachad          #+#    #+#             */
/*   Updated: 2024/11/11 02:31:40 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (s < d)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main()
{
    char str1[50] = "Hello, World!";
    char str2[50];

    ft_memmove(str2, str1, ft_strlen(str1) + 1);

    printf("Source: %s\n", str1);
    printf("Destination after memmove: %s\n", str2);

    ft_memmove(str1 + 7, str1, 6);
    printf("After overlapping memmove: %s\n", str1);

    return 0;
}*/
