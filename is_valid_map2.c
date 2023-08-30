/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:13:03 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 13:59:11 by tshigeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*skip_header(char *str);
char	*ft_strchr(char *s, int c);

int	is_valid_line(char *str)
{
	char	*new_str;
	int		log;
	int		count;

	new_str = skip_header(str);
	log = 0;
	count = 0;
	while (*new_str != '\0')
	{
		if (*new_str == '\n')
		{
			if (log == 0)
			{
				log = count + 1;
			}
			else if (log != count)
				return (0);
			count = 0;
		}
		count++;
		new_str++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}

int	is_at_least_one_row(char *str)
{
	char	*new_str;

	new_str = skip_header(str);
	if (new_str == NULL)
		return (0);
	return (ft_strchr(new_str, '\n') != NULL);
}

