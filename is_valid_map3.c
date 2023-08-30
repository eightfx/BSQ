/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:44:10 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 17:44:39 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

int	is_length_valid(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len >= 4);
}

int	is_chars_valid(char *str, int len)
{
	int	i;

	i = len - 1;
	while (i >= len - 3)
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i--;
	}
	return (1);
}

int	is_number_valid(char *str, int len)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (i <= len - 4)
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num > 0);
}

// Validates the header of the map string.
// The header must be in the format:
// <Numeric String><printable char><printable char><printable char>\n
// The function checks if the last three characters
// before the newline are printable
// and if the preceding part consists only of numeric characters.
//
// @args:
// - str: Pointer to the start of the map string which includes the header.
//
// @returns:
// - int: Returns 1 if the header is valid, 0 otherwise.
int	is_valid_header(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (!is_length_valid(str))
		return (0);
	if (!is_chars_valid(str, len))
		return (0);
	if (!is_number_valid(str, len))
		return (0);
	return (1);
}
