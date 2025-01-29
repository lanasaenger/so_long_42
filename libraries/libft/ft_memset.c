/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:53:55 by lamachad          #+#    #+#             */
/*   Updated: 2024/10/21 22:14:10 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h>

// int main() {
//     char str[50] = "Olá, mundo!";
//     printf("Antes: %s\n", str);

//     // Chamando a função ft_memset
//     ft_memset(str, '*', 5);

//     printf("Depois: %s\n", str);
//     return 0;
//}
