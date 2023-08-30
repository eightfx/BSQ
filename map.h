/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigeta <tshigeta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:44:22 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/30 18:00:20 by tshigeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_map
{
	int		row_len;
	int		col_len;
	char	empty;
	char	obstacle;
	char	full;
	int		**map;
}			t_map;

int			is_at_least_one_row(char *str);
int			is_valid_line(char *str);
char		*ft_strchr(char *s, int c);
void		put_error(void);
t_map		parse_map(char *str);
void		print_map_matrix(t_map parsed_map);
int			create_square(t_map main);
int			solve(t_map main);
char		*read_file_into_str(char *path);
int			is_valid_map(char *str);
void		get_answer(t_map square_map);
char		*read_input(void);
int			ft_strlen(char *str);
char		*ft_strncpy(char *dest, char *src, size_t n);
int			ft_atoi(char *str);
char		*copy_to_new_memory(char *content, char *buffer, ssize_t total_size,
				ssize_t bytes_read);
char		*skip_header(char *str);
int			is_newline_at_end(char *str);
int			row_error(char *str);
void		free_map(t_map *map);
int			is_valid_header(char *str);

#endif // MAP_H
