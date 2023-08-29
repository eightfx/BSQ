#include <unistd.h>

void	ft_putchartekina(int x_pos, int y_pos, t_map square_map)
{
	if (square_map.map[y_pos][x_pos] == 1)
		write(1, &square_map.full, 1);
	else if (square_map.map[y_pos][x_pos] == -1)
		write(1, &square_map.obstacle, 1);
	else if (square_map.map[y_pos][x_pos] == 0)
		write(1, &square_map.empty, 1);
}

void get_answer(t_map square_map)
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
			ft_putchartekina(x_pos, y_pos, square_map);
			x_pos++;
		}
		write(1, "\n", 1);
		y_pos++;
	}
}
