/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:12:58 by lamachad          #+#    #+#             */
/*   Updated: 2024/10/17 20:59:45 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
/*
#include <stdio.h>

int	main(void)
{
	char	i = '5';
	char	j = 'g';

	printf("%d\n", ft_isdigit(i));
	printf("%d\n", ft_isdigit(j));
}*/
