/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 20:22:35 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/23 00:18:13 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			index;
	int			is_minus;
	long long	int_accumulator;

	index = 0;
	is_minus = 0;
	int_accumulator = 0;
	while (str[index] != '\0' && (str[index] == '\t' || str[index] == '\n'
		|| str[index] == '\v' || str[index] == '\f'
		|| str[index] == '\r' || str[index] == ' '))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			is_minus = !is_minus;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		int_accumulator = int_accumulator * 10 + (str[index] - '0');
		index++;
	}
	if (is_minus)
		int_accumulator = -int_accumulator;
	return ((int)int_accumulator);
}

int				ft_printf_atoi(const char *start, int *num)
{
	int		index;
	int		ptr;
	int		accumulator;

	index = 0;
	accumulator = 0;
	while (start[index] == '0')
	{
		index++;
	}
	while (start[index] >= '0' && start[index] <= '9')
	{
		ptr = start[index] - '0';
		accumulator = accumulator * 10 + ptr;
		index++;
	}
	*num = index;
	return (accumulator);
}