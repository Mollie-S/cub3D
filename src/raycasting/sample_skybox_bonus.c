/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sample_skybox_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 11:37:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 18:00:23 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sample_skybox.h"
#include "utils.h"
#include "draw_frame.h"

unsigned int	sample_skybox(t_game_engine_state *state, int y,
	double ray_angle)
{
	double	skybox_x;
	double	skybox_y;

	ray_angle = wrap_angle(ray_angle * 2.0);
	skybox_x = ray_angle / 360.0;
	skybox_y = (double)y / (state->style->resolution.y / 2.0);
	return (sample_texture(&state->tex_info[TEXTURE_SKYBOX],
			skybox_x, skybox_y));
}
