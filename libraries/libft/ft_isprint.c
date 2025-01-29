/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:48:26 by lamachad          #+#    #+#             */
/*   Updated: 2024/10/17 20:59:42 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char h = '#';
// 	char i = '\n';

// 	printf("%d\n", ft_isprint(h));
// 	printf("%d\n", ft_isprint(i));
// }
