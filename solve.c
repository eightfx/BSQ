#include "map.h"

int		**parse_map(char *str);

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

// #include <stdio.h>
// #include <stdlib.h>

// void	print_map(int **map, int rows, int cols)
// {
// 	for (int i = 0; i < rows; i++)
// 	{
// 		for (int j = 0; j < cols; j++)
// 		{
// 			printf("%d ", map[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

/* int	main(void) */
/* { */
/* 	char	*str; */
/* 	int		**map; */

/* 	str = "10.ox\n....o..o..\n...o......\n....o...o.\n.........o\n..o......o\n..o.o...o.\n.o........\n....o.o.o.\nooo...o...\n.......o.o\n"; */
/* 	map = parse_map(str); */
/* 	solve(map); */
/* 	print_map(map, 10, 10); */
/* } */
