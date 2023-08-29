/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:47:14 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/29 16:51:13 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	my_memcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

// ファイルを開く
int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
	return (fd);
}

// バッファから新しいメモリにデータをコピー
char	*copy_to_new_memory(char *content, char *buffer, ssize_t total_size,
		ssize_t bytes_read)
{
	char	*new_content;

	new_content = malloc(total_size + bytes_read + 1);
	if (content)
	{
		my_memcpy(new_content, content, total_size);
		free(content);
	}
	my_memcpy(new_content + total_size, buffer, bytes_read);
	return (new_content);
}

// ファイルからデータを読み取る
char	*read_file_into_str(char *path)
{
	int		fd;
	char	buffer[1024];
	char	*content;
	ssize_t	total_size;
	ssize_t	bytes_read;

	fd = open_file(path);
	if (fd == -1)
		return (NULL);
	content = NULL;
	total_size = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		content = copy_to_new_memory(content, buffer, total_size, bytes_read);
		total_size += bytes_read;
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (content)
		content[total_size] = '\0';
	close(fd);
	return (content);
}
