#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(char *s, int c);

char	*skip_header(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '\n');
	return ((ptr != NULL) ? (ptr + 1) : NULL);
}

int	is_at_least_one_row(char *str)
{
	char	*new_str;

	new_str = skip_header(str);
	if (new_str == NULL)
		return (0);
	return (ft_strchr(new_str, '\n') != NULL);
}

int	is_newline_at_end(char *str)
{
	char	*new_str;

	new_str = skip_header(str);
	if (new_str == NULL)
		return (0);
	return (new_str[strlen(new_str) - 1] == '\n');
}

int	is_valid_characters(char *str, char empty_char, char obstacle_char,
		char full_char)
{
	char	*new_str;
	char	*ptr;

	new_str = skip_header(str);
	if (new_str == NULL)
		return (0);
	ptr = new_str;
	while (*ptr != '\0')
	{
		if (*ptr != empty_char && *ptr != obstacle_char && *ptr != full_char
			&& *ptr != '\n')
		{
			return (0);
		}
		ptr++;
	}
	return (1);
}

int	is_valid_header(char *str, char *empty_char, char *obstacle_char,
		char *full_char)
{
	char	*ptr;
	int		rows;

	ptr = str;
	rows = 0;
	// 行数の読み込み
	while (*ptr >= '0' && *ptr <= '9')
	{
		rows = rows * 10 + (*ptr - '0');
		ptr++;
	}
	*empty_char = *ptr++;
	*obstacle_char = *ptr++;
	*full_char = *ptr++;
	if (*ptr != '\n' && *ptr != '\0')
	{
		return (0);
	}
	if (*empty_char == *obstacle_char || *empty_char == *full_char
		|| *obstacle_char == *full_char)
	{
		return (0);
	}
	return (1);
}

int	is_valid_map(char *str)
{
	char	empty_char;
	char	obstacle_char;
	char	full_char;

	if (!is_valid_header(str, &empty_char, &obstacle_char, &full_char))
		return (0);
	if (!is_valid_characters(str, empty_char, obstacle_char, full_char))
		return (0);
	if (!is_newline_at_end(str))
		return (0);
	if (!is_at_least_one_row(str))
		return (0);
	return (1);
}

/* int	main(void) */
/* { */
/* 	char str[] = "10.ox\n....o..o..\n...o......\n....o...o.\n.........o\n..o......o\n..o.o...o.\n.o........\n....o.o.o.\nooo...o...\n.......o.o\n"; */
/* 	printf("%d\n", is_valid_map(str)); */
/* } */
