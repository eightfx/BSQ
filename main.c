/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:30 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 13:29:38 by tshigeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

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

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	t_map	map;
	char	buffer[1024];
	ssize_t	bytes_read;

	if (argc == 1)
	{
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
		if (bytes_read >= 0)
			buffer[bytes_read] = '\0';
		map = parse_map(buffer);
		get_answer(map);
		printf("\n\n");
		solve(map);
		create_square(map);
		get_answer(map);
		return (0);
	}
	else
	{
		i = 0;
		while (i < argc - 1)
		{
			str = read_file_into_str(argv[i + 1]);
			map = parse_map(str);
			get_answer(map);
			printf("\n\n");
			solve(map);
			create_square(map);
			get_answer(map);
			write(1, "\n", 1);
			i++;
		}
		return (0);
	}
}
