/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:47:00 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/29 16:47:02 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

t_map	parse_map(char *str);

int	this_is_boundry(int x_pos, int y_pos)
{
	if (x_pos == 0 || y_pos == 0)
		return (1);
	return (0);
}

int	up_left(int x_pos, int y_pos, int **map)
{
	if (this_is_boundry(x_pos, y_pos))
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
