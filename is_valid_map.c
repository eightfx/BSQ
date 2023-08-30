/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:12 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 13:33:47 by tshigeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "map.h"

char	*ft_strchr(char *s, int c);
t_map	parse_map(char *str);
char	*ft_strchr(char *s, int c);
int		is_at_least_one_row(char *str);
int		is_valid_line(char *str);

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

int	is_newline_at_end(char *str)
{
	char	*new_str;

	new_str = skip_header(str);
	if (new_str == NULL)
		return (0);
	return (new_str[strlen(new_str) - 1] == '\n');
}

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
		if (*ptr != str[len - 3] && *ptr != str[len - 2] && *ptr != str[len - 1]
			&& *ptr != '\n')
			return (0);
		ptr++;
	}
	return (1);
}

int	is_valid_header(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (len < 4)
		return (0);
	i = len - 1;
	while (i >= len - 3)
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i--;
	}
	i = 0;
	while (i <= len - 4)
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_map(char *str)
{
	if (!is_valid_header(str))
		return (0);
	if (!is_valid_characters(str))
		return (0);
	if (!is_newline_at_end(str))
		return (0);
	if (!is_at_least_one_row(str))
		return (0);
	if (!is_valid_line(str))
		return (0);
	return (1);
}
