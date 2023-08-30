/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:16:38 by tshigeta          #+#    #+#             */
/*   Updated: 2023/08/30 17:58:42 by tshigeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	get_row(char *str)
{
	char	*ptr;
	char	row_str[100];
	int		len;

	ptr = str;
	while (*ptr != '\n' && *ptr != '\0')
		ptr++;
	len = ptr - str;
	ft_strncpy(row_str, str, len - 3);
	row_str[len - 3] = '\0';
	return (ft_atoi(row_str));
}

int	row_error(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	if (count == get_row(str) + 1)
		return (1);
	return (0);
}
