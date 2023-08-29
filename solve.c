int this_is_boundry(int	x_pos, int	y_pos)
{
	if (x_pos == 0 || y_pos == 0)
		return (1);
	return (0);
}

int	up_left(int x_pos, int y_pos, int **map)
{
	if (this_is_boundry(x_pos, y_pos))
		return (1);
	if (map[y_pos][x_pos - 1] == -1
		|| map[y_pos - 1][x_pos] == -1
		|| map[y_pos - 1][x_pos - 1] == -1)
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

int	solve(int **map)
{
	int	x_pos;
	int y_pos;

	x_pos = 0;
	y_pos = 0;
	while (map[y_pos])
	{
		x_pos = 0;
		while (map[y_pos][x_pos])
		{
			if (map[y_pos][x_pos] == 0)
				map[y_pos][x_pos] = up_left(x_pos, y_pos, map);
			x_pos++;
		}
		y_pos++;
	}
	return (1);
}

#include <stdio.h>
#include <stdlib.h>

void print_map(int **map, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int **map = malloc(5 * sizeof(int *));
	for (int i = 0; i < 5; i++)
	{
		map[i] = malloc(5 * sizeof(int));
		for (int j = 0; j < 5; j++)
		{
			map[i][j] = 0;
		}
	}
	map[0][0] = 0;
	map[0][1] = 0;
	map[0][2] = 0;
	map[0][3] = 0;
	map[0][4] = 0;
	map[1][0] = 0;
	map[1][1] = -1;
	map[1][2] = 0;
	map[1][3] = 0;
	map[1][4] = 0;
	map[2][0] = 0;
	map[2][1] = 0;
	map[2][2] = 0;
	map[2][3] = 0;
	map[2][4] = 0;
	map[3][0] = 0;
	map[3][1] = 0;
	map[3][2] = -1;
	map[3][3] = 0;
	map[3][4] = 0;
	map[4][0] = 0;
	map[4][1] = 0;
	map[4][2] = 0;
	map[4][3] = 0;
	map[4][4] = 0;
	printf("Before solving:\n");
	print_map(map, 5, 5);
	solve(map);
	printf("After solving:\n");
	print_map(map, 5, 5);
	for (int i = 0; i < 5; i++)
	{
		free(map[i]);
	}
	free(map);

	return 0;
}
