/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:30 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 15:53:03 by tshigeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void	put_str(char *str);
t_map	parse_map(char *str);
void	print_map_matrix(t_map parsed_map);
void	create_square(t_map main);
int		solve(t_map main);
char	*read_file_into_str(char *path);
int		is_valid_map(char *str);
void	get_answer(t_map square_map);

// int	main(void)
// {
// 	char	*str;
// 	t_map	map;

// 	str = read_file_into_str("map.txt");
// 	map = parse_map(str);
// 	get_answer(map);
// 	printf("\n\n");
// 	solve(map);
// 	create_square(map);
// 	get_answer(map);
// }

void	main_0(void)
{
	t_map	map;
	char	buffer[1024];
	ssize_t	bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	if (bytes_read >= 0)
		buffer[bytes_read] = '\0';
	if (!is_valid_map(buffer))
	{
		put_str("map error\n");
		return ;
	}
	map = parse_map(buffer);
	solve(map);
	create_square(map);
	get_answer(map);
}

void	main_1(int argc, char **argv)
{
	int		i;
	char	*str;
	t_map	map;

	i = 0;
	while (i < argc - 1)
	{
		str = read_file_into_str(argv[i + 1]);
		if (!is_valid_map(str))
			put_str("map error\n");
		else
		{
			map = parse_map(str);
			solve(map);
			create_square(map);
			get_answer(map);
			write(1, "\n", 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		main_0();
		return (0);
	}
	else
	{
		main_1(argc, argv);
		return (0);
	}
}
