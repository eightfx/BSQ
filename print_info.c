#include "map.h"
#include <stdio.h>
#include <stdlib.h>

void	print_map_info(t_map parsed_map)
{
	printf("Row Length: %d\n", parsed_map.row_len);
	printf("Column Length: %d\n", parsed_map.col_len);
	printf("Empty char: %c\n", parsed_map.empty);
	printf("Obstacle char: %c\n", parsed_map.obstacle);
	printf("Full char: %c\n", parsed_map.full);
}

void	print_map_matrix(t_map parsed_map)
{
	int	row;
	int	col;

	row = 0;
	while (row < parsed_map.row_len)
	{
		col = 0;
		while (col < parsed_map.col_len)
		{
			// 各数値を3文字幅で出力（2桁数値＋1つのスペース）
			printf("%3d", parsed_map.map[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}

void	free_map_memory(t_map parsed_map)
{
	int	i;

	i = 0;
	while (i < parsed_map.row_len)
	{
		free(parsed_map.map[i]);
		i++;
	}
	free(parsed_map.map);
}

/* int	main(void) */
/* { */
/* 	t_map	parsed_map; */

/* 	char str[] = "3.o\nooo\no.o\nooo"; // テスト用のマップ文字列。 */
/* 	parsed_map = parse_map(str); */
/* 	print_map_info(parsed_map); */
/* 	printf("Map:\n"); */
/* 	print_map_matrix(parsed_map); */
/* 	free_map_memory(parsed_map); */
/* 	return (0); */
/* } */
