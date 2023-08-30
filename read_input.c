/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:05:22 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 16:21:23 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

char	*read_input(void)
{
	char	buffer[1024];
	char	*content;
	ssize_t	total_size;
	ssize_t	bytes_read;

	content = NULL;
	total_size = 0;
	bytes_read = read(0, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		content = copy_to_new_memory(content, buffer, total_size, bytes_read);
		if (content == NULL)
			return (NULL);
		total_size += bytes_read;
		bytes_read = read(0, buffer, sizeof(buffer) - 1);
	}
	return (content);
}
