/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 17:23:46 by osamara       #+#    #+#                 */
/*   Updated: 2020/11/10 00:39:24 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	const char *ptr;

	ptr = s + ft_strlen(s);
	if (((char)c) == '\0')
	{
		return (((char*)ptr));
	}
	while (ptr != s - 1)
	{
		if (*ptr != ((char)c))
		{
			ptr--;
		}
		else
		{
			return (((char*)ptr));
		}
	}
	return (NULL);
}
