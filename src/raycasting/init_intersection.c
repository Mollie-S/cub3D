/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_intersection.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 17:16:52 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 17:52:11 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init_intersection.h"

void	init_intersection_result(t_intersection_result *result)
{
	result->dist_to_wall = 0.0;
	result->wall_height = 0.0;
	result->current_tex = NULL;
	result->tex_x = 0.0;
	result->tex_y = 0.0;
}

void	init_tracer(t_tracer *tracer, double ray_angle)
{
	tracer->x = -1.0;
	tracer->y = -1.0;
	tracer->step_x = 0.0;
	tracer->step_y = 0.0;
	tracer->ray_angle = ray_angle;
}
