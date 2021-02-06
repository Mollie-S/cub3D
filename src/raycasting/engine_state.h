/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   engine_state.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:16 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/06 15:53:05 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_STATE_H
# define ENGINE_STATE_H

# define TILE_SIZE 1

typedef struct		s_engine_state
{
	double		FOV;
	double		dist_to_plane;
	double		pos_x;
	double		pos_y;
	double		ray_angle;
	// double		radian;
}					t_engine_state;


#endif