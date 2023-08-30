/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:12 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 17:49:54 by tshigeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// Skips the header of the map string.
// This function returns a pointer that skips over the header and points
// to the first character of the first row in the map.
//
// @args:
// - str: Pointer to the start of the map string which includes the header.
//
// @returns:
// - char *: Returns a pointer to the first character after the header.
//   Returns NULL if the header is not terminated by a newline character.
char	*skip_header(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '\n');
	if (ptr != NULL)
		ptr = ptr + 1;
	else
		ptr = NULL;
	return (ptr);
}

// Validates the characters used in the map.
// This function checks if all characters in the map (excluding the header)
// are either one of the three specified characters in the header or a newline.
//
// @args:
// - str: Pointer to the start of the map string which includes the header.
//
// @returns:
// - int: Returns 1 if the map only contains valid characters, 0 otherwise.
int	is_valid_characters(char *str)
{
	char	*new_str;
	char	*ptr;
	int		len;

	ptr = str;
	while (*ptr != '\n' && *ptr != '\0')
		ptr++;
	len = ptr - str;
	new_str = skip_header(str);
	if (new_str == NULL)
		return (0);
	ptr = new_str;
	while (*ptr != '\0')
	{
		if (*ptr != str[len - 3] && *ptr != str[len - 2] && *ptr != '\n')
			return (0);
		ptr++;
	}
	return (1);
}

int	is_valid_member(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len - 1] == str[len - 2] || str[len - 1] == str[len - 3]
		|| str[len - 2] == str[len - 3])
		return (0);
	return (1);
}

// Validates the entire map, including its header and contents.
// This function calls other validation functions to perform
// comprehensive validation on the map.
//
// @args:
// - str: Pointer to the start of the map string which includes the header.
//
// @returns:
// - int: Returns 1 if the map is valid, 0 otherwise.
int	is_valid_map(char *str)
{
	if (!is_valid_header(str))
		return (0);
	if (!is_valid_member(str))
		return (0);
	if (!is_valid_characters(str))
		return (0);
	if (!is_newline_at_end(str))
		return (0);
	if (!is_at_least_one_row(str))
		return (0);
	if (!is_valid_line(str))
		return (0);
	if (!row_error(parse_map(str), str))
		return (0);
	return (1);
}
