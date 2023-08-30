/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:04 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 16:18:30 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

// Outputs a single character based on the value at a given position in the map.
// This function writes the appropriate
// character ('full', 'obstacle', or 'empty')
// to the standard output, depending on the value
// in the map at the specified position.
//
// @args:
// - x_pos: The x-coordinate of the position in the map.
// - y_pos: The y-coordinate of the position in the map.
// - square_map: The t_map structure containing the map information.
//
// @returns:
// - void
void	ft_putanswer(int x_pos, int y_pos, t_map square_map)
{
	if (square_map.map[y_pos][x_pos] == 1)
		write(1, &square_map.full, 1);
	else if (square_map.map[y_pos][x_pos] == -1)
		write(1, &square_map.obstacle, 1);
	else if (square_map.map[y_pos][x_pos] == 0)
		write(1, &square_map.empty, 1);
}

// Outputs the entire map to the standard output.
// This function iterates through each position
// in the map and calls ft_putanswer
// to output the appropriate character.
// Each row is followed by a newline character.
//
// @args:
// - square_map: The t_map structure containing the map information.
//
// @returns:
// - void
void	get_answer(t_map square_map)
{
	int	x_pos;
	int	y_pos;

	x_pos = 0;
	y_pos = 0;
	while (y_pos < square_map.row_len)
	{
		x_pos = 0;
		while (x_pos < square_map.col_len)
		{
			ft_putanswer(x_pos, y_pos, square_map);
			x_pos++;
		}
		write(1, "\n", 1);
		y_pos++;
	}
}
