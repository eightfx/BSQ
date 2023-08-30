/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:45:55 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 14:34:49 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

// Searches for the maximum value in the given map.
// This function scans the entire map to find the maximum value stored in it,
// which typically represents the largest square possible.
//
// @args:
// - main: The t_map structure containing the map information.
// - flag_x: Pointer to store the x-coordinate of the position
//               with the maximum value.
// - flag_y: Pointer to store the y-coordinate of the position
//               with the maximum value.
//
// @returns:
// - int: The maximum value found in the map.
int	ft_searchmax(t_map main, int *flag_x, int *flag_y)
{
	int	flag;
	int	x_pos;
	int	y_pos;

	x_pos = 0;
	y_pos = 0;
	flag = 0;
	while (y_pos < main.row_len)
	{
		x_pos = 0;
		while (x_pos < main.col_len)
		{
			if (main.map[y_pos][x_pos] > flag)
			{
				flag = main.map[y_pos][x_pos];
				*flag_x = x_pos;
				*flag_y = y_pos;
			}
			x_pos++;
		}
		y_pos++;
	}
	return (flag);
}

// Draws the largest square in the map.
// This function fills in the map with the largest possible square centered
// at (flag_x, flag_y) and with size 'flag'.
//
// @args:
// - main: The t_map structure containing the map information.
// - flag_x: The x-coordinate of the center of the largest square.
// - flag_y: The y-coordinate of the center of the largest square.
// - flag: The size of the largest square.
//
// @returns:
// - void
void	ft_drawsquare(t_map main, int flag_x, int flag_y, int flag)
{
	int	x_pos;
	int	y_pos;

	x_pos = 0;
	y_pos = 0;
	while (y_pos < main.row_len)
	{
		x_pos = 0;
		while (x_pos < main.col_len)
		{
			if (flag_x - flag < x_pos && x_pos <= flag_x && flag_y
				- flag < y_pos && y_pos <= flag_y)
				main.map[y_pos][x_pos] = 1;
			else if (main.map[y_pos][x_pos] != -1)
				main.map[y_pos][x_pos] = 0;
			x_pos++;
		}
		y_pos++;
	}
}

// Creates the largest possible square in the map.
// This function calls ft_searchmax to find the largest possible square and then
// calls ft_drawsquare to draw this square in the map.
//
// @args:
// - main: The t_map structure containing the map information.
//
// @returns:
// - int: Always returns 1 to indicate that the square was successfully created.
int	create_square(t_map main)
{
	int	flag_x;
	int	flag_y;
	int	flag;

	flag_x = -1;
	flag_y = -1;
	flag = ft_searchmax(main, &flag_x, &flag_y);
	ft_drawsquare(main, flag_x, flag_y, flag);
	return (1);
}
