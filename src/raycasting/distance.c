/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distance.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:43:34 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/11 20:55:34 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "distance.h"

#include "utils.h"

#include <math.h>

/*
**	distance to horizontal intersection
**  you can see that the distance between xi is the same
**		0°
**    |____/next xi_________
** 	  |   /
**    |__/_next xi_________ 	90°
**    | /
**   _|/____________
**  xi|
**					 distance between xi = x_step;
** 		180°
**  if we know the angle as our 0 axis is vertical
**  we measure our angle from vertical 0
**	slope = tan(angle) = dist between xi's / height
**  so:dist between xi and next xi = height * tan where height = 1.0
*/

double		dist_to_hor_inters(t_game_engine_state *state, t_tracer *hor_tracer)
{
	hor_tracer->type = TRACER_HORIZONTAL;
	hor_tracer->y = floor(state->pos_y);
	hor_tracer->step_y = -1.0;
	if (hor_tracer->ray_angle >= 90.0 && hor_tracer->ray_angle < 270.0)
	{
		hor_tracer->y = floor(state->pos_y) + 1.0;
		hor_tracer->step_y = 1.0;
	}
	hor_tracer->x = state->pos_x + fabs((state->pos_y - hor_tracer->y)
		* tan(DEG2RAD(hor_tracer->ray_angle)));
	hor_tracer->step_x = fabs(tan(DEG2RAD(hor_tracer->ray_angle)));
	if (hor_tracer->ray_angle >= 180.0 && hor_tracer->ray_angle < 360.0)
	{
		hor_tracer->x = state->pos_x - fabs((state->pos_y - hor_tracer->y)
			* tan(DEG2RAD(hor_tracer->ray_angle)));
		hor_tracer->step_x = -hor_tracer->step_x;
	}
	return (distance_to_wall(state, hor_tracer));
}

/*
**	find vertical intersection
**  you can see that the distance between xi is the same
**		0°
**    |   | /
** 	  |   |/
**    |  /|next yi       	90°
**    | / |
**    |/  |
**   /|yi
**					 distance between yi = y_step;
** 		180°
**
**	slope = tan(angle) = width / dist between yi's
**  so: dist between yi = width / tan(angle) where width = 1.0
*/

double		dist_to_ver_inters(t_game_engine_state *state, t_tracer *ver_tracer)
{
	ver_tracer->type = TRACER_VERTICAL;
	ver_tracer->x = floor(state->pos_x) + 1.0;
	ver_tracer->step_x = 1.0;
	if (ver_tracer->ray_angle >= 180.0 && ver_tracer->ray_angle < 360.0)
	{
		ver_tracer->x = floor(state->pos_x);
		ver_tracer->step_x = -ver_tracer->step_x;
	}
	ver_tracer->y = state->pos_y - fabs((state->pos_x - ver_tracer->x)
		/ tan(DEG2RAD(ver_tracer->ray_angle)));
	ver_tracer->step_y = -1.0 / fabs(tan(DEG2RAD(ver_tracer->ray_angle)));
	if (ver_tracer->ray_angle >= 90.0 && ver_tracer->ray_angle < 270.0)
	{
		ver_tracer->y = state->pos_y + fabs((state->pos_x - ver_tracer->x)
			/ tan(DEG2RAD(ver_tracer->ray_angle)));
		ver_tracer->step_y = -ver_tracer->step_y;
	}
	return (distance_to_wall(state, ver_tracer));
}

/*
** a correction is needed for left and top walls
*/

double		distance_to_wall(t_game_engine_state *state, t_tracer *tracer)
{
	size_t		index;
	double		distance;

	distance = INFINITY;
	while (tracer->x < state->map->width && tracer->y < state->map->height
		&& tracer->x >= 0 && tracer->y >= 0)
	{
		if (tracer->step_x < 0 && tracer->type == TRACER_VERTICAL)
			index = state->map->width * (size_t)tracer->y
			+ (size_t)tracer->x - 1;
		else if (tracer->step_y < 0 && tracer->type == TRACER_HORIZONTAL)
			index = state->map->width * ((size_t)tracer->y - 1)
			+ (size_t)tracer->x;
		else
			index = state->map->width * (size_t)tracer->y + (size_t)tracer->x;
		if (state->map->fields[index] == FIELD_WALL)
		{
			distance = fabs((state->pos_x - tracer->x)
				/ sin(DEG2RAD(tracer->ray_angle)));
			break ;
		}
		tracer->x += tracer->step_x;
		tracer->y += tracer->step_y;
	}
	return (distance);
}
