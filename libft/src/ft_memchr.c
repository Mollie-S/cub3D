/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:01:10 by osamara       #+#    #+#                 */
/*   Updated: 2020/11/02 17:16:40 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;

	ptr = ((unsigned char*)s);
	while (n > 0)
	{
		if (*ptr == ((unsigned char)c))
		{
			return (ptr);
		}
		else
		{
			ptr++;
			n--;
		}
	}
	return (NULL);
}
