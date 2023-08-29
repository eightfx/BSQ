int	ft_searchmax(int **map, int *flag_x, int *flag_y)
{
	int	flag;
	int	x_pos;
	int	y_pos;

	x_pos = 0;
	y_pos = 0;
	flag = 0;
	while (map[y_pos])
	{
		x_pos = 0;
		while (map[y_pos][x_pos])
		{
			if (map[y_pos][x_pos] > flag)
			{
				flag = map[y_pos][x_pos];
				*flag_x = x_pos;
				*flag_y = y_pos;
			}
			x_pos++;
		}
		y_pos++;
	}
	return (flag);
}

ft_drawsquare(int **map, int flag_x, int flag_y, int flag)

int create_square(int **map)
{
	int flag_x;
	int flag_y;
	int flag;

	flag_x = -1;
	flag_y = -1;
	flag = ft_searchmax(map, flag_x, flag_y);
	ft_drawsquare(map, flag_x, flag_y, flag);
}
