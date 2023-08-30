/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:47:14 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 16:23:13 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// Copies n bytes from source to destination.
// This is a basic implementation of the standard memcpy function.
//
// @args:
// - dest: Pointer to the destination array.
// - src: Pointer to the source array.
// - n: Number of bytes to copy.
//
// @returns:
// - void
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

// Opens a file for reading.
// This function tries to open a file with read-only access mode.
//
// @args:
// - path: The path of the file to open. Should be a null-terminated string.
//
// @returns:
// - int: File descriptor if the file is successfully opened.
//   Returns -1 if the file cannot be opened.
int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

// Copies existing content and buffer into a new dynamically allocated memory.
// This function allocates a new memory block large enough to hold both the
// existing content and the new bytes read from the buffer, and then performs
// the copy operation.
//
// @args:
// - content: Pointer to existing content. Could be NULL.
// - buffer: Pointer to the read buffer.
// - total_size: Size of the existing content.
// - bytes_read: Number of bytes recently read into the buffer.
//
// @returns:
// - char *: A pointer to a dynamically allocated string that contains both
//   the existing content and the buffer. NULL if memory allocation fails.
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

// Read the contents of a file into a dynamically allocated string.
// This function reads chunks of data from the file into a buffer,
// and then copies each chunk into a dynamically allocated string.
//
// @args:
// - path: The path of the file to read. Should be a null-terminated string.
//
// @returns:
//  - char *: A pointer to a dynamically allocated string containing
//    the file content.
//   Returns NULL if the file cannot be opened or read.
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
