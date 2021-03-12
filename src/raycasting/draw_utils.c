/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 00:21:37 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/12 00:20:16 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "draw_utils.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
