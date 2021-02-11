/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersection.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 20:04:19 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/11 10:56:28 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "game_engine/game_engine_state.h"

# include <stddef.h>

typedef enum		e_tracer_type
{
	TRACER_VERTICAL,
	TRACER_HORIZONTAL
}					t_tracer_type;

typedef struct      s_tracer
{
	double			x;
	double			y;
	double			step_x;
	double			step_y;
	t_tracer_type	type;
	double			ray_angle;
}                   t_tracer;

typedef struct      s_intersection_result
{
	double			dist_to_wall;
	double			wall_height;
	t_texture_info	*current_tex;
	double			tex_x;
	double			tex_y;
}					t_intersection_result;


#endif