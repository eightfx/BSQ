#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_map	parse_map(char *str);
void	print_map_matrix(t_map parsed_map);
void	create_square(t_map main);
int		solve(t_map main);
char	*read_file_into_str(char *path);

void	get_answer(t_map square_map);

int	main(void)
{
	char	*str;
	t_map	map;

	str = read_file_into_str("map.txt");
	map = parse_map(str);
	get_answer(map);
	printf("\n\n");
	solve(map);
	create_square(map);
	get_answer(map);
}
