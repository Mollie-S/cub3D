/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_intersection.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 17:18:04 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 17:52:28 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_INTERSECTION_H
# define INIT_INTERSECTION_H

# include "intersection.h"

void	init_intersection_result(t_intersection_result *result);
void	init_tracer(t_tracer *tracer, double ray_angle);

#endif
