/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sample_skybox_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 11:37:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/14 14:47:11 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sample_skybox.h"

unsigned int		sample_skybox(t_game_engine_state *state, int y, double ray_angle)
{
	double skybox_x;
	double skybox_y;

	skybox_x = ray_angle / 360;
	skybox_y = (double)y / (state->style->resolution.y / 2);
	return (sample_texture(state->tex_info, skybox_x, skybox_y));
}
