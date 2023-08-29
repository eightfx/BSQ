#include "map.h"

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
			if (flag_x - flag < x_pos && x_pos <= flag_x
				&& flag_y - flag < y_pos && y_pos <= flag_y)
				main.map[y_pos][x_pos] = 1;
			else if (main.map[y_pos][x_pos] != -1)
				main.map[y_pos][x_pos] = 0;
			x_pos++;
		}
		y_pos++;
	}
}

int create_square(t_map main)
{
	int flag_x;
	int flag_y;
	int flag;

	flag_x = -1;
	flag_y = -1;
	flag = ft_searchmax(main, &flag_x, &flag_y);
	ft_drawsquare(main, flag_x, flag_y, flag);
	return (1);
}
