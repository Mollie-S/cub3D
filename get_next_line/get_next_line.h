/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 11:47:27 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/26 15:46:22 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define END_OF_FILE 0
# define ERR -1
# define GNL_NOT_FOUND 0
# define FOUND 1

typedef	struct	s_vector
{
	char		*container;
	ssize_t		size;
	ssize_t		capacity;
	int			is_eof;
}				t_vector;

int				get_next_line(int fd, char **line);
int				initialize_buffer(t_vector *b);
int				handle_newline(char **line, t_vector *b);
int				read_text(int fd, char **line, t_vector *b);
int				realloc_buffer(t_vector *b, ssize_t newline_len);
int				alloc_big_container(t_vector *b, ssize_t newln_len);
ssize_t			count_newline_len(t_vector *b);
char			*move_content(char *dst, char *src, ssize_t len);
char			*copy_newline(char *src, long long n);
void			free_memory(t_vector *b);
#endif
