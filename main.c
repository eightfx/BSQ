/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:30 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 17:28:28 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	main_0(void)
{
	t_map	map;
	char	*buffer;
	char	*str_sub;

	buffer = read_input();
	if (buffer == NULL)
	{
		put_error();
		return ;
	}
	if (!is_valid_map(buffer))
	{
		put_error();
		free(buffer);
		return ;
	}
	str_sub = buffer;
	map = parse_map(buffer);
	solve(map);
	create_square(map);
	get_answer(map);
	free_map(&map);
	free(buffer);
}

void	main_1(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*str_sub;
	t_map	map;

	i = 0;
	while (i < argc - 1)
	{
		str = read_file_into_str(argv[i + 1]);
		str_sub = str;
		if (str == NULL)
			put_error();
		else if (!is_valid_map(str))
			put_error();
		else
		{
			map = parse_map(str);
			solve(map);
			create_square(map);
			get_answer(map);
			free_map(&map);
		}
		if (argc > 2)
			write(1, "\n", 1);
		free(str);
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
