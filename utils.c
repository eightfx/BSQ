/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:50 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 16:47:11 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Copies up to n characters from the string pointed to by src to dest.
//
// @args:
// - dest: Pointer to the destination array.
// - src: Pointer to the source string.
// - n: Number of characters to copy.
//
// @returns:
// - char *: Returns the destination string.
char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// Converts the initial portion of the string pointed to by str to an integer.
//
// @args:
// - str: Pointer to the string to convert.
//
// @returns:
// - int: The integer value of the converted string.
int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

// Locates the first occurrence of c in the string pointed to by s.
//
// @args:
// - s: The string in which to search.
// - c: The character to search for.
//
// @returns:
// - char *: A pointer to the first occurrence of
//              the character c in the string s.
char	*ft_strchr(char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

// Writes a error to the standard output
//
// @returns:
// - void
void	put_error(void)
{
	write(2, "map error\n", 10);
}

// Calculates the length of the string str,
// not including the terminating null character.
//
// @args:
// - str: The string whose length is to be calculated.
//
// @returns:
// - int: The length of the string.
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
