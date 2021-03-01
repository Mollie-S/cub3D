/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_frame.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:25:09 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 17:42:33 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render_frame.h"

#include "init_intersection.h"
#include "distance.h"
#include "render_sprite.h"
#include "draw_frame.h"
#include "utils.h"
#include "result.h"

#include "mlx.h"

#include <math.h>
#include <stdlib.h>

/*
** Multiplying result.dist_to_wall(distorted distance)
** to the cos() to remove distortion.
*/

int	render_frame(t_game_engine_state *state)
{
	double					ray_angle;
	t_intersection_result	result;
	int						x;

	handle_sprites(state);
	init_intersection_result(&result);
	x = 0;
	while (x < state->style->resolution.x)
	{
		ray_angle = state->direction
			 + RAD2DEG(atan((x - state->style->resolution.x
						 / 2.0) / state->dist_to_plane));
		ray_angle = wrap_angle(ray_angle);
		define_current_wall(state, ray_angle, &result);
		result.dist_to_wall *= cos(DEG2RAD(state->direction - ray_angle));
		result.wall_height = 1.0 / result.dist_to_wall * state->dist_to_plane;
		draw_vertical_line(state, &result, x, ray_angle);
		draw_sprites_vertical_line(state, x, result.dist_to_wall);
		x++;
	}
	mlx_put_image_to_window(state->window->mlx, state->window->mlx_win,
		state->window->img, 0, 0);
	return (SUCCESS);
}

/*
** if distance to horizontal intersection (dist_x) is less than
** distance to vertical intersection (dist_y) it means that
** we hit a NO or SO wall.  Otherwise a side wall - WE or EA.
** if step_x is negative we're moving to the left, to the WE direction
** because our coordinates start at the top left corner
*/

void	define_current_wall(t_game_engine_state *state,
	double ray_angle, t_intersection_result *result)
{
	double		dist_x;
	double		dist_y;
	t_tracer	hor_tracer;
	t_tracer	ver_tracer;

	init_tracer(&hor_tracer, ray_angle);
	init_tracer(&ver_tracer, ray_angle);
	dist_x = dist_to_hor_inters(state, &hor_tracer);
	dist_y = dist_to_ver_inters(state, &ver_tracer);
	if (dist_y < dist_x)
	{
		result->dist_to_wall = dist_y;
		set_sidewalls_tex_coord(state, &ver_tracer, result);
	}
	else
	{
		result->dist_to_wall = dist_x;
		set_frontwalls_tex_coord(state, &hor_tracer, result);
	}
}

/*
** common practice for tex coordinates in graphics is
** to use relative size (1.0)
** result->tex_x = 1.0 - offset_on_wall is the correction
** for north and west walls
*/

void	set_sidewalls_tex_coord(t_game_engine_state *state,
	t_tracer *ver_tracer, t_intersection_result *result)
{
	double		offset_on_wall;

	offset_on_wall = (ver_tracer->y - floor(ver_tracer->y));
	if (ver_tracer->step_x < 0)
	{
		result->current_tex = &state->tex_info[TEXTURE_WE];
		result->tex_x = 1.0 - offset_on_wall;
	}
	else
	{
		result->current_tex = &state->tex_info[TEXTURE_EA];
		result->tex_x = offset_on_wall;
	}
}

void	set_frontwalls_tex_coord(t_game_engine_state *state,
	t_tracer *hor_tracer, t_intersection_result *result)
{
	double		offset_on_wall;

	offset_on_wall = (hor_tracer->x - floor(hor_tracer->x));
	if (hor_tracer->step_y < 0)
	{
		result->current_tex = &state->tex_info[TEXTURE_NO];
		result->tex_x = 1.0 - offset_on_wall;
	}
	else
	{
		result->current_tex = &state->tex_info[TEXTURE_SO];
		result->tex_x = offset_on_wall;
	}
}
