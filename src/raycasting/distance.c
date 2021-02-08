/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distance.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:43:34 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 23:57:48 by osamara       ########   odam.nl         */
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
** 	  |   /								if we know the angle
**    |__/_next xi_________ 	90°	 	as our 0 axis is vertical we measure our angle from vertical 0
**    | /                           	slope = tan(angle) = dist between xi's / height
**   _|/____________                	so:dist between xi and next xi = height * tan where height = 1.0
**  xi|
**					 distance between xi = x_step;
** 		180°
*/

double		dist_to_hor_inters(t_game_engine_state *state, t_tracer *hor_inters)
{
    hor_inters->type = TRACER_HORIZONTAL;
    hor_inters->y = floor(state->pos_y);
    hor_inters->step_y = -1.0;
    if (hor_inters->ray_angle >= 90.0 && hor_inters->ray_angle < 270.0)
    {
        hor_inters->y = floor(state->pos_y) + 1.0;
        hor_inters->step_y = 1.0;
    }
    hor_inters->x = state->pos_x + fabs((state->pos_y - hor_inters->y)
        * tan(DEG2RAD(hor_inters->ray_angle)));
    hor_inters->step_x = fabs(tan(DEG2RAD(hor_inters->ray_angle)));
    if (hor_inters->ray_angle >= 180.0 && hor_inters->ray_angle < 360.0)
    {
        hor_inters->x = state->pos_x - fabs((state->pos_y - hor_inters->y)
            * tan(DEG2RAD(hor_inters->ray_angle)));
        hor_inters->step_x = -hor_inters->step_x;
    }
    return (distance_to_wall(state, hor_inters));
}

/*
**	find vertical intersection
**  you can see that the distance between xi is the same
**		0°
**    |   | /
** 	  |   |/							if we know the angle
**    |  /|next yi       	90°	 	  as our 0 axis is vertical we measure our angle from vertical 0
**    | / |                         	slope = tan(angle) = width / dist between yi's
**    |/  |              	so: dist between yi = width / tan(angle) where width = 1.0
**   /|yi
**					 distance between yi = y_step;
** 		180°
**
*/

double		dist_to_ver_inters(t_game_engine_state *state, t_tracer *vert_inters)
{
    vert_inters->type = TRACER_VERTICAL;
    vert_inters->x = floor(state->pos_x) + 1.0;
    vert_inters->step_x = 1.0;
    if (vert_inters->ray_angle >= 180.0 && vert_inters->ray_angle < 360.0)
    {
        vert_inters->x = floor(state->pos_x);
        vert_inters->step_x = -vert_inters->step_x;
    }
    vert_inters->y = state->pos_y - fabs((state->pos_x - vert_inters->x)
        / tan(DEG2RAD(vert_inters->ray_angle)));
    vert_inters->step_y = -1.0 / fabs(tan(DEG2RAD(vert_inters->ray_angle)));
    if (vert_inters->ray_angle >= 90.0 && vert_inters->ray_angle < 270.0)
    {
        vert_inters->y = state->pos_y + fabs((state->pos_x - vert_inters->x)
            / tan(DEG2RAD(vert_inters->ray_angle)));
        vert_inters->step_y = -vert_inters->step_y;
    }
    return (distance_to_wall(state, vert_inters));
}

double			distance_to_wall(t_game_engine_state *state, t_tracer *tracer)
{
    size_t		field_index;
    double		distance;

    distance = INFINITY;
    while (tracer->x < state->map->width && tracer->y < state->map->height
        && tracer->x >= 0 && tracer->y >= 0)
    {
        if (tracer->step_x < 0 && tracer->type == TRACER_VERTICAL)
            field_index = state->map->width * (size_t)tracer->y + (size_t)tracer->x - 1;
        else if (tracer->step_y < 0 && tracer->type == TRACER_HORIZONTAL)
            field_index = state->map->width * ((size_t)tracer->y - 1) + (size_t)tracer->x;
        else
            field_index = state->map->width * (size_t)tracer->y + (size_t)tracer->x;
        if (state->map->fields[field_index] == FIELD_WALL)
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
