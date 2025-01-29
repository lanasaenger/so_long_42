/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:57:56 by lamachad          #+#    #+#             */
/*   Updated: 2024/10/17 20:59:48 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	j = '{';
// 	char	k = '+';
// 	char	l = '4';
// 	char	m = 'o';

// 	printf("%d\n", ft_isascii(j));
// 	printf("%d\n", ft_isascii(k));
// 	printf("%d\n", ft_isascii(l));
// 	printf("%d\n", ft_isascii(m));
// }
