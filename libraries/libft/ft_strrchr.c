/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:53:44 by lamachad          #+#    #+#             */
/*   Updated: 2024/10/28 18:33:19 by lamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
// #include <stdio.h>
// int main() {
//     const char *str = "exemplo de string";
//     char c = 's';

//     char *resultado = strrchr(str, c);

//     if (resultado) {
//         printf("Última ocorrência de '%c': %s\n", c, resultado);
//     } else {
//         printf("'%c' não encontrado.\n", c);
//     }

//     return 0;
// }
