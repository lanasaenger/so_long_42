/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:23:39 by lamachad          #+#    #+#             */
/*   Updated: 2024/10/18 18:53:57 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>

int main() {
    char str[20] = "Hello, World!";

    printf("Antes do ft_bzero: '%s'\n", str);

    ft_bzero(str + 7, 6);

    printf("Depois do ft_bzero: '%s'\n", str);

    return 0;
}*/
