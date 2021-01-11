/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:31:21 by osamara       #+#    #+#                 */
/*   Updated: 2020/11/01 23:23:39 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char *ptr;

	ptr = s;
	while (*ptr)
	{
		ptr++;
	}
	return (ptr - s);
}
