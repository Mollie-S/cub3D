/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:36:44 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 10:04:17 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stdlib.h>

double  wrap_angle(double angle)
{
	while (angle < 0.0)
		angle += 360.0;
	while (angle > 360.0)
		angle -= 360.0;
	return (angle);
}

void	free_array_memory(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_map(t_map *map)
{
	free(map->fields);
	map->fields = NULL;
}