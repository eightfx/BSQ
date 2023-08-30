/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:16:38 by tshigeta          #+#    #+#             */
/*   Updated: 2023/08/30 16:25:08 by tshigeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	row_error(t_map main, char *str)
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
	if (count == main.row_len + 1)
		return (1);
	return (0);
}
