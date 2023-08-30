/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:13:03 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 16:13:40 by tshigeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// Validates the uniformity of line lengths in a map.
// This function iterates through each line in the map, excluding the header,
// and checks if all the lines have the same length.
//
// @args:
// - str: The entire map string including the header.
//
// @returns:
// - int: Returns 1 if all lines have the same length, 0 otherwise.
int	is_valid_line(char *str)
{
	char	*new_str;
	int		log;
	int		count;

	new_str = skip_header(str);
	log = 0;
	count = 0;
	while (*new_str != '\0')
	{
		if (*new_str == '\n')
		{
			if (log == 0)
				log = count + 1;
			else if (log != count)
				return (0);
			count = 0;
		}
		count++;
		new_str++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}

// Checks if the map contains at least one row.
// This function looks for the presence of at least one row (line) in the map,
// excluding the header.
//
// @args:
// - str: The entire map string including the header.
//
// @returns:
// - int: Returns 1 if at least one row is present, 0 otherwise.
int	is_at_least_one_row(char *str)
{
	char	*new_str;

	new_str = skip_header(str);
	if (new_str == NULL)
		return (0);
	return (ft_strchr(new_str, '\n') != NULL);
}

// Checks if the last character of the map string is a newline character.
// This function verifies if the map string terminates with a newline character.
//
// @args:
// - str: Pointer to the start of the map string which includes the header.
//
// @returns:
// - int: Returns 1 if the last character is a newline, 0 otherwise.
int	is_newline_at_end(char *str)
{
	char	*new_str;

	new_str = skip_header(str);
	if (new_str == NULL)
		return (0);
	return (new_str[strlen(new_str) - 1] == '\n');
}
