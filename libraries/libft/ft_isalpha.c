/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:42:51 by lamachad          #+#    #+#             */
/*   Updated: 2024/10/17 20:59:51 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
/*
#include <stdio.h>

int	main(void)
{
	char	*i = "kshdgfb";
	char	*j = "90";

	while (*i)
	{
		printf("%d\n", ft_isalpha(*i));
		i++;
	}
	while (*j)
	{
		printf("%d\n", ft_isalpha(*j));
		j++;
	}
	return (0);
}*/
