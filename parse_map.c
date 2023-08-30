/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:44:48 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 14:52:45 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_strlen(char *str);
void	put_str(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strncpy(char *dest, char *src, size_t n);
int		ft_atoi(char *str);

// Parses the header information
// from the given string and fills the t_map struct.
//
// @args:
// - str: Pointer to the string that contains the map
//         information including the header.
// - map: Pointer to the t_map struct
//        where the header information will be stored.
//
// @returns:
// - void
void	parse_header(char *str, t_map *map)
{
	char	*ptr;
	char	row_str[100];
	int		len;

	ptr = str;
	while (*ptr != '\n' && *ptr != '\0')
		ptr++;
	len = ptr - str;
	map->full = str[len - 1];
	map->obstacle = str[len - 2];
	map->empty = str[len - 3];
	ft_strncpy(row_str, str, len - 3);
	row_str[len - 3] = '\0';
	map->row_len = ft_atoi(row_str);
}

// Allocates memory for the map's 2D array and initializes it.
//
// @args:
// - map: Pointer to the t_map struct where the 2D array will be stored.
// - col_len: The number of columns in the 2D array.
//
// @returns:
// - void
void	create_empty_map_array(t_map *map, int col_len)
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

// Fills the map's 2D array with values
// based on the characters in the given string.
//
// @args:
// - str: Pointer to the string that contains the map information.
// - map: Pointer to the t_map struct where the 2D array will be filled.
//
// @returns:
// - void
void	fill_map_array(char *str, t_map *map)
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
			map->map[row][col] = -1;
		else if (*ptr == map->empty)
			map->map[row][col] = 0;
		else if (*ptr == '\n')
		{
			row++;
			col = -1;
		}
		col++;
		ptr++;
	}
}

// Parses the given string to create and return a t_map struct
// filled with the map's information.
//
// @args:
// - str: Pointer to the string that contains the map information.
//
// @returns:
// - t_map: A struct containing all parsed information about the map.
t_map	parse_map(char *str)
{
	t_map	parsed_map;
	char	*header_end;

	header_end = ft_strchr(str, '\n');
	parse_header(str, &parsed_map);
	parsed_map.col_len = ft_strlen(header_end + 1) / parsed_map.row_len - 1;
	create_empty_map_array(&parsed_map, parsed_map.col_len);
	fill_map_array(str, &parsed_map);
	return (parsed_map);
}
