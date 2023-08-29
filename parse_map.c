#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

void	parse_header(char *str, int *rows, char *empty_char,
		char *obstacle_char)
{
	sscanf(str, "%d%c%c", rows, empty_char, obstacle_char);
}

int	**create_empty_array(int rows)
{
	int	**array;
	int	i;

	array = malloc(rows * sizeof(int *));
	i = 0;
	while (i < rows)
	{
		array[i] = malloc(rows * sizeof(int));
		i++;
	}
	return (array);
}

void	fill_array(int **array, char *str, char empty_char, char obstacle_char)
{
	char	*ptr;
	int		row;
	int		col;

	// Find the first newline character to skip the header
	ptr = strchr(str, '\n');
	if (ptr == NULL)
	{
		// Handle error: No newline character found
		return ;
	}
	row = 0;
	col = 0;
	// Skip the header and start from the next character after '\n'
	ptr++;
	while (*ptr != '\0')
	{
		if (*ptr == obstacle_char)
		{
			array[row][col] = -1;
		}
		else if (*ptr == empty_char)
		{
			array[row][col] = 0;
		}
		else if (*ptr == '\n')
		{
			row++;
			col = -1;
		}
		col++;
		ptr++;
	}
}

int	**parse_map(char *str)
{
	int	rows;
	int	**array;

	char empty_char, obstacle_char;
	// Parse the header to get rows, empty_char, and obstacle_char
	parse_header(str, &rows, &empty_char, &obstacle_char);
	printf("obstacle_char: %c\n", obstacle_char);
	printf("empty_char: %c\n", empty_char);
	// Create an empty 2D array based on the number of rows
	array = create_empty_array(rows);
	// Fill the array based on the map string
	fill_array(array, str, empty_char, obstacle_char);
	return (array);
}

/* int	main(void) */
/* { */
/* 	char	*str; */
/* 	int		**map; */
/* 	int		i; */
/* 	int		j; */

/* 	str = "10.ox\n....o..o..\n...o......\n....o...o.\n.........o\n..o......o\n..o.o...o.\n.o........\n....o.o.o.\nooo...o...\n.......o.o\n"; */
/* 	map = parse_map(str); */
/* 	// 確認用: 2次元配列を出力 */
/* 	i = 0; */
/* 	while (i < 10) */
/* 	{ */
/* 		j = 0; */
/* 		while (j < 10) */
/* 		{ */
/* 			printf("%d ", map[i][j]); */
/* 			j++; */
/* 		} */
/* 		printf("\n"); */
/* 		i++; */
/* 	} */
/* 	// メモリ解放 */
/* 	i = 0; */
/* 	while (i < 10) */
/* 	{ */
/* 		free(map[i]); */
/* 		i++; */
/* 	} */
/* 	free(map); */
/* 	return (0); */
/* } */
