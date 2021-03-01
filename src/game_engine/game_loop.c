/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_loop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 20:58:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 18:19:20 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"
#include "movement.h"
#include "sprite.h"
#include "key_handling.h"
#include "raycasting/render_frame.h"
#include "report_error.h"
#include "result.h"
#include "utils.h"
#include "bitmap.h"

#include "mlx.h"

#include <math.h>

int	game_loop(t_window *window, t_style *style, t_map *map, int screenshot)
{
	t_game_engine_state	state;
	t_movement			move;
	t_sprite			sprite;

	init_game_engine_state(&state, window, style, map);
	if (!load_textures(&state))
		return (ERROR);
	if (map->sprites_num > 0)
	{
		init_sprite(&state, &sprite);
		if (!load_sprite_coordinates(&state))
			return (ERROR);
	}
	if (create_screenshot(&state, screenshot) == ERROR)
		return (ERROR);
	else
	{
		init_movement(&move);
		setup_key_hooks(&state);
		mlx_loop_hook(window->mlx, update_frame, &state);
		mlx_loop(window->mlx);
	}
	return (SUCCESS);
}

void	init_game_engine_state(t_game_engine_state *state, t_window *window,
	t_style *style, t_map *map)
{
	state->window = window;
	state->style = style;
	state->map = map;
	state->dist_to_plane = (style->resolution.x / 2.0)
		/ tan(deg2rad(FOV / 2.0));
	state->pos_x = map->start_pos_x + 0.5;
	state->pos_y = map->start_pos_y + 0.5;
	state->direction = map->start_direction;
	state->sprites = NULL;
}

int	load_textures(t_game_engine_state *state)
{
	int				i;
	char			*path;
	t_texture_info	*ti;

	i = 0;
	while (i < TEXTURE_COUNT)
	{
		path = state->style->textures[i];
		if (path != NULL)
		{
			ti = &state->tex_info[i];
			ti->img = mlx_xpm_file_to_image(state->window->mlx, path,
					&ti->img_width, &ti->img_height);
			if (ti->img == NULL)
			{
				return (report_error("Error reading a texture image"));
			}
			ti->addr = mlx_get_data_addr(ti->img, &ti->bpp,
					&ti->line_length, &ti->endian);
		}
		i++;
	}
	return (SUCCESS);
}

int	update_frame(t_game_engine_state *state)
{
	if (state->move.rotation_dir != 0)
		rotate_player(state);
	if (state->move.move_ver_dir != 0 || state->move.move_hor_dir != 0)
		move_player(state);
	render_frame(state);
	return (0);
}

int	create_screenshot(t_game_engine_state *state, int screenshot)
{
	if (screenshot == TRUE)
	{
		update_frame(state);
		if (!create_bmp_file(state))
			return (ERROR);
	}
	return (SUCCESS);
}
