/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:37:52 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/06 20:01:47 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "map/map.h"

double	deg2rad(double angle);
double	rad2deg(double angle);
double	wrap_angle(double angle);
void	free_array_memory(char **array);

#endif