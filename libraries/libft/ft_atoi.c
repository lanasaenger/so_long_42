/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:01:41 by lamachad          #+#    #+#             */
/*   Updated: 2024/10/17 23:17:13 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sig;

	result = 0;
	sig = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			sig = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - 48);
		nptr++;
	}
	return (sig * result);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\t%d\n", ft_atoi("123"), atoi("123"));
	printf("%d\t%d\n", ft_atoi(" -123"), atoi(" -123"));
	printf("%d\t%d\n", ft_atoi("1 23"), atoi("1 23"));
	printf("%d\t%d\n", ft_atoi("abc123"), atoi("abc123"));
	return (0);
}
*/
