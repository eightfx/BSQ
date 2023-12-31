/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:07:20 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 17:07:31 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row_len)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}
