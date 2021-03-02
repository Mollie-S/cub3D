/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 11:47:14 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 23:35:05 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	get_next_line(int fd, char **line)
{
	static t_vector		b;
	int					newline_result;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!initialize_buffer(&b))
		return (-1);
	while (!b.is_eof)
	{
		if (b.size > 0)
		{
			newline_result = handle_newline(line, &b);
			if (newline_result == ERR || newline_result == FOUND)
				return (newline_result);
		}
		if (!read_text(fd, line, &b))
			return (-1);
	}
	free_memory(&b);
	return (0);
}

int	initialize_buffer(t_vector *b)
{
	if (b->container == NULL)
	{
		if (!alloc_big_container(b, 0))
			return (0);
	}
	return (1);
}

int	read_text(int fd, char **line, t_vector *b)
{
	ssize_t				bytes_read;

	bytes_read = read(fd, (b->container + b->size), BUFFER_SIZE);
	if (bytes_read == ERR)
	{
		free_memory(b);
		return (0);
	}
	if (bytes_read == END_OF_FILE)
	{
		b->is_eof = 1;
		*line = copy_newline(b->container, b->size);
		b->size = 0;
	}
	else
		b->size = b->size + bytes_read;
	return (1);
}

int	realloc_buffer(t_vector *b, ssize_t newline_len)
{
	ssize_t		unused_mem;

	b->size = b->size - newline_len;
	unused_mem = b->capacity - b->size;
	if (unused_mem >= BUFFER_SIZE)
	{
		if (!move_content(b->container, b->container + newline_len, b->size))
			return (0);
	}
	else
	{
		if (!alloc_big_container(b, newline_len))
			return (0);
	}
	return (1);
}

int	alloc_big_container(t_vector *b, ssize_t newln_len)
{
	ssize_t		temp_size;
	ssize_t		more_capacity;
	char		*big_container;

	temp_size = b->size;
	if (b->container == NULL && BUFFER_SIZE < 128)
		more_capacity = 128;
	else
		more_capacity = b->capacity + (BUFFER_SIZE - (b->capacity - b->size));
	big_container = (char *)malloc(sizeof(char) * more_capacity);
	if (!big_container)
	{
		free_memory(b);
		return (0);
	}
	if (!move_content(big_container, b->container + newln_len, b->size))
		return (0);
	free_memory(b);
	b->container = big_container;
	b->capacity = more_capacity;
	b->size = temp_size;
	return (1);
}
