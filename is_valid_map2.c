/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:13:03 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 14:27:27 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*skip_header(char *str);
char	*ft_strchr(char *s, int c);

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
			{
				log = count + 1;
			}
			else if (log != count)
				return (0);
			count = 0;
		}
		count++;
		new_str++;
	}
	return (1);
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
