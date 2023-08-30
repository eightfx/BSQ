/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:47:00 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 14:26:17 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

t_map	parse_map(char *str);

// Checks if a cell is on the boundary of a map.
// Returns 1 if the cell is on the boundary (either x_pos or y_pos is zero),
// otherwise returns 0.
//
// @args:
// - x_pos: The x-coordinate of the cell.
// - y_pos: The y-coordinate of the cell.
//
// @returns:
// - int: Returns 1 if on boundary, 0 otherwise.
int	is_boundry(int x_pos, int y_pos)
{
	if (x_pos == 0 || y_pos == 0)
		return (1);
	return (0);
}

// Determines the value of a cell based on its neighbors.
// This function takes the values of the neighboring cells and uses them to
// determine the value of the current cell.
//
// @args:
// - x_pos: The x-coordinate of the cell.
// - y_pos: The y-coordinate of the cell.
// - map: A 2D array representing the map.
//
// @returns:
// - int: The value that should be placed in the cell at (x_pos, y_pos).
int	up_left(int x_pos, int y_pos, int **map)
{
	if (is_boundry(x_pos, y_pos))
		return (1);
	if (map[y_pos][x_pos - 1] == -1 || map[y_pos - 1][x_pos] == -1 || map[y_pos
		- 1][x_pos - 1] == -1)
		return (1);
	if (map[y_pos][x_pos - 1] < map[y_pos - 1][x_pos])
	{
		if (map[y_pos][x_pos - 1] < map[y_pos - 1][x_pos - 1])
			return (map[y_pos][x_pos - 1] + 1);
		return (map[y_pos - 1][x_pos - 1] + 1);
	}
	if (map[y_pos - 1][x_pos] < map[y_pos - 1][x_pos - 1])
		return (map[y_pos - 1][x_pos] + 1);
	return (map[y_pos - 1][x_pos - 1] + 1);
}

// Populates the map with correct values.
// This function iterates through every cell in the map and determines its value
// based on its neighboring cells.
//
// @args:
// - main: A structure containing the map details including row
//    and column lengths and the 2D map array.
//
// @returns:
// - int: Returns 1 upon successful completion.
int	solve(t_map main)
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
			if (main.map[y_pos][x_pos] == 0)
				main.map[y_pos][x_pos] = up_left(x_pos, y_pos, main.map);
			x_pos++;
		}
		y_pos++;
	}
	return (1);
}
