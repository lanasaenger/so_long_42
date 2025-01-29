/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:22:03 by lamachad          #+#    #+#             */
/*   Updated: 2024/11/11 23:33:39 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	h[] = "lavinia";

// 	printf("%zu\n", ft_strlen(h));
// }
