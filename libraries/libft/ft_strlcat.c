/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:12:20 by lamachad          #+#    #+#             */
/*   Updated: 2024/11/11 23:32:57 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	i = 0;
	if (size <= len1)
		return (len2 + size);
	while (src[i] && len1 + i < (size -1))
	{
		dst[len1 + i] = src[i];
		i++;
	}
	dst[len1 + i] = '\0';
	return (len1 + len2);
}
// #include <stdio.h>
// int main() {
//     char dst[20] = "Hello, ";
//     const char *src = "World!";
//     size_t size = sizeof(dst);

//     size_t result = ft_strlcat(dst, src, size);
//     printf("Resultado: %s\n", dst);
//     printf("Total Length: %zu\n", result);

//     return 0;
// }
