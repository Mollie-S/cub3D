/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:25:09 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/09 00:00:10 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render_scene.h"

#include "distance.h"
#include "draw_scene.h"
#include "utils.h"

#include <math.h>

static void		init_tracer(t_tracer *tracer, t_map *map)
{
	tracer->x = -1.0;
	tracer->y = -1.0;
	tracer->step_x = 0.0;
	tracer->step_y = 0.0;
	tracer->ray_angle = map->start_direction;
}

static void		init_intersection_result(t_intersection_result *inters_result)
{
	inters_result->dist_to_wall = 0;
	inters_result->wall_height = 0;
	inters_result->current_texture = NULL;
	inters_result->current_color = 0;
	inters_result->texture_x = 0;
	inters_result->texture_y = 0;
}

void			render_scene(t_game_engine_state *state)
{
	t_tracer				tracer;
	t_intersection_result	inters_result;
	int						i;

	init_tracer(&tracer, state->map);
	init_intersection_result(&inters_result);
	i = 0;
	while (i < state->style->resolution.x)
	{
		tracer.ray_angle = state->map->start_direction + RAD2DEG(atan((i - state->style->resolution.x / 2.0)
			/ state->dist_to_plane)));
			tracer.ray_angle = wrap_angle(tracer.ray_angle);
			define_current_wall(state, &tracer, &inters_result);
			inters_result.dist_to_wall *= cos(DEG2RAD(state->map->start_direction - tracer.ray_angle));
			inters_result.wall_height = 1.0 / inters_result.dist_to_wall * state->dist_to_plane;
			draw_vertical_line(state->window, &inters_result, &state->style->resolution, &i);
			i++;
	}
	draw_image(state->window);
}

void			define_current_wall(t_game_engine_state *state, t_tracer *tracer, t_intersection_result *inters_result)
{
	double		dist_x;
	double		dist_y;

	dist_x = dist_to_hor_inters(state, tracer);
	dist_y = dist_to_ver_inters(state, tracer);
	if (dist_y < dist_x)
	{
		if (tracer->step_x < 0) // if it's a west wall
			inters_result->current_color = 0x00FFFFFF; //white
		else
			inters_result->current_color = 0x00FF0000; // east wall red
		//define texture coordinates, define texture path
		inters_result->dist_to_wall = dist_y;
	}
	else
	{
		inters_result->dist_to_wall = dist_x;
		if (tracer->step_y < 0) //north wall
			inters_result->current_color = 0x0000FF00; //green
		else
			inters_result->current_color = 0x000000FF; //south wall blue
		//define texture coordinates, define texture path
	}
}
