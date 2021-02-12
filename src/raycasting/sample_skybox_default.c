/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sample_skybox_default.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 11:37:23 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/12 11:44:27 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sample_skybox_default.h"

unsigned int		sample_skybox(t_game_engine_state *state, int y, double ray_angle)
{
	double skybox_x;
	double skybox_y;

	skybox_x = ray_angle / 360;
	skybox_y = (double)y / (state->style->resolution.y / 2);
	return (state->style->ceiling_rgb);
}
