/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:40:07 by lamachad          #+#    #+#             */
/*   Updated: 2024/10/17 22:10:36 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
#include <stdio.h>
int	main(void)
{
	char	l = 'i';
	char	a = '7';
	char	v = '~';

	printf("%d\n%d\n%d\n", ft_isalnum(l), ft_isalnum(a), ft_isalnum(v));
}*/
