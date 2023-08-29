/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:44:48 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/29 15:15:48 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char		*ft_strchr(char *s, int c);

static void	parse_header(char *str, t_map *map)
{
	sscanf(str, "%d%c%c%c", &map->row_len, &map->empty, &map->obstacle,
		&map->full);
}

static void	create_empty_map_array(t_map *map, int col_len)
{
	int	i;

	i = 0;
	map->map = malloc(map->row_len * sizeof(int *));
	while (i < map->row_len)
	{
		map->map[i] = malloc(col_len * sizeof(int));
		i++;
	}
}

static void	fill_map_array(char *str, t_map *map)
{
	char	*ptr;
	int		row;
	int		col;

	ptr = ft_strchr(str, '\n') + 1;
	row = 0;
	col = 0;
	while (*ptr != '\0')
	{
		if (*ptr == map->obstacle)
		{
			map->map[row][col] = -1;
		}
		else if (*ptr == map->empty)
		{
			map->map[row][col] = 0;
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

t_map	parse_map(char *str)
{
	t_map	parsed_map;
	char	*header_end;

	header_end = ft_strchr(str, '\n');
	parse_header(str, &parsed_map);
	parsed_map.col_len = strlen(header_end + 1) / parsed_map.row_len - 1;
	create_empty_map_array(&parsed_map, parsed_map.col_len);
	fill_map_array(str, &parsed_map);
	return (parsed_map);
}
