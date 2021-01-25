/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 11:47:52 by osamara       #+#    #+#                 */
/*   Updated: 2020/11/25 11:10:44 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int			handle_newline(char **line, t_vector *b)
{
	ssize_t		newline_len;

	newline_len = count_newline_len(b);
	if (newline_len == NOT_FOUND)
	{
		if ((b->capacity - b->size) < BUFFER_SIZE)
		{
			if (!realloc_buffer(b, newline_len))
				return (ERR);
		}
		return (NOT_FOUND);
	}
	*line = copy_newline(b->container, newline_len - 1);
	if (!*line)
	{
		free_memory(b);
		return (ERR);
	}
	if (!realloc_buffer(b, newline_len))
		return (ERR);
	return (FOUND);
}

ssize_t		count_newline_len(t_vector *b)
{
	ssize_t		length;
	char		*ptr;

	length = 0;
	ptr = b->container;
	while (length < b->size)
	{
		if (*ptr != '\n')
		{
			ptr++;
			length++;
		}
		else
		{
			length++;
			return (length);
		}
	}
	return (NOT_FOUND);
}

char		*copy_newline(char *src, long long n)
{
	char *dst;
	char *dst_current;

	if (!src)
		return (NULL);
	dst = (char*)malloc(sizeof(char) * (n + 1));
	if (!dst)
	{
		return (NULL);
	}
	dst_current = dst;
	while (n > 0)
	{
		*dst_current = *src;
		dst_current++;
		src++;
		n--;
	}
	*dst_current = '\0';
	return (dst);
}

char		*move_content(char *dst, char *src, ssize_t len)
{
	char	*dst_current;

	dst_current = dst;
	while (len > 0)
	{
		*dst_current = *src;
		dst_current++;
		src++;
		len--;
	}
	return (dst);
}

void		free_memory(t_vector *b)
{
	free(b->container);
	b->container = NULL;
	b->size = 0;
	b->capacity = 0;
	b->is_eof = 0;
}
