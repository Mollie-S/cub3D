/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:36:44 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/05 13:54:11 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stdlib.h>
#include <math.h>

double	deg2rad(double angle)
{
	return (angle * M_PI / 180.0 + (double)(0.0001));
}

double	rad2deg(double angle)
{
	return (angle * 180.0 / M_PI);
}

double	wrap_angle(double angle)
{
	while (angle < 0.0)
		angle += 360.0;
	while (angle > 360.0)
		angle -= 360.0;
	return (angle);
}

void	free_array_memory(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
