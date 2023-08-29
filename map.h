/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:44:22 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/29 16:44:23 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAP_H
# define MAP_H

typedef struct t_map
{
	int		row_len;
	int		col_len;
	char	empty;
	char	obstacle;
	char	full;
	int		**map;
}			t_map;

#endif // MAP_H
