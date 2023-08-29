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

char	*read_file_into_str(char *path)
{
	int		fd;
	ssize_t	bytes_read;
	char	*new_content;
	char	buffer[1024];
	char	*content;
	ssize_t	total_size;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}
	content = NULL;
	total_size = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read <= 0)
		{
			break ;
		}
		new_content = malloc(total_size + bytes_read + 1);
		if (content)
		{
			my_memcpy(new_content, content, total_size);
			free(content);
		}
		my_memcpy(new_content + total_size, buffer, bytes_read);
		content = new_content;
		total_size += bytes_read;
	}
	if (content)
	{
		content[total_size] = '\0';
	}
	close(fd);
	return (content);
}
