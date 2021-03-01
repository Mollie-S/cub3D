/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:37:52 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 18:18:00 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "map.h"

double	deg2rad(double angle);
double	rad2deg(double angle);
double	wrap_angle(double angle);
void	free_array_memory(char **array);
void	free_map(t_map *map);

#endif