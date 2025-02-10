/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:12:30 by lamachad          #+#    #+#             */
/*   Updated: 2025/02/10 13:46:27 by lavinia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Verifica se a nova posição contém uma parede ('1')
int	can_move(char **map_grid, int new_x, int new_y)
{
	if (map_grid[new_y][new_x] == '1')
		return (0);
	return (1);
}
//mvimento do player
// void	move_player(int *position_y, int *position_x, char **map_grid, char direction)
// {
// 	int	new_x = *position_x;
// 	int	new_y = *position_y;

// 	position_x = 0;
// 	position_y = 0;
// 	if (direction == 'w')
// 		position_y--;
		
	
// }