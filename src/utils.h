/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:37:52 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 18:08:22 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "map.h"

# define DEG2RAD(angle) ((angle) * M_PI / 180.0 + (double)(0.0001))
# define RAD2DEG(angle) ((angle) * 180.0 / M_PI)

double	wrap_angle(double angle);
void	free_array_memory(char **array);
void	free_map(t_map *map);

#endif