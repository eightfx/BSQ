/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:30 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 16:20:10 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	main_0(void)
{
	t_map	map;
	char	*buffer;

	buffer = read_input();
	if (buffer == NULL)
	{
		put_str("map error\n");
		return ;
	}
	if (!is_valid_map(buffer))
	{
		put_str("map error\n");
		free(buffer);
		return ;
	}
	map = parse_map(buffer);
	solve(map);
	create_square(map);
	get_answer(map);
	free(buffer);
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
