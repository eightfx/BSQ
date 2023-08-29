#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_map	parse_map(char *str);
void	print_map_matrix(t_map parsed_map);
void	create_square(t_map main);
int		solve(t_map main);

int	main(void)
{
	char	*str;
	t_map	map;

	str = "10.ox\n....o..o..\n...o......\n....o...o.\n.........o\n..o......o\n..o.o...o.\n.o........\n....o.o.o.\nooo...o...\n.......o.o\n";
	map = parse_map(str);
	print_map_matrix(map);
	printf("\n\n");
	solve(map);
	print_map_matrix(map);
	printf("\n\n");
	create_square(map);
	print_map_matrix(map);
}
