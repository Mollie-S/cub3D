/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_state.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:16 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 13:57:15 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_STATE_H
# define CAMERA_STATE_H

typedef struct		s_camera_state
{
	double		dist_to_plane;
	double		pos_x;
	double		pos_y;
	double		ray_angle;
}					t_camera_state;


#endif