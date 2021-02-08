/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:25:09 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 10:49:24 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h> //remove

#include "mlx.h"
#include "render_scene.h"



void	my_mlx_pixel_put(t_window *window, int x, int y, unsigned int color)
{
	char *dst;

	dst = window->address + (y * window->line_length + x * (window->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_vertical_line(t_window *window, t_intersection_result *inters_res, t_resolution *resolution, int *num)
{
	int		line_start;
	int		line_end;
	int		x;
	int		y;

	line_start = resolution->y / 2 - (int)inters_res->wall_height / 2;
	line_end = resolution->y / 2 + (int)inters_res->wall_height / 2;
	y = line_start;
	while (y <= line_end)
	{
		x = *num;
		if (x == *num)
		{
			my_mlx_pixel_put(window, x, y, inters_res->current_color);
			x++;
		}
		y++;
	}

}

void	draw_image(t_window *window)
{
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img, 0, 0);
	mlx_loop(window->mlx);
}

/*
**	horizontal intersection
**  you can see that the distance between xi is the same
**		0°
**    |____/next xi_________
** 	  |   /								if we know the angle
**    |__/_next xi_________ 	90°	 	as our 0 axis is vertical we measure our angle from vertical 0
**    | /                           	slope = tan(angle) = dist between xi's / height
**   _|/____________                	so:dist between xi and next xi = height * tan where height = TILE_SIZE
**  xi|
**					 distance between xi = x_step;
** 		180°
*/


double			distance_to_wall(t_intersection *intersection, t_engine_state *engine_state, t_map *map)
{
	size_t		field_index;
	double		distance;

	distance = INFINITY;
	while (intersection->x < map->width && intersection->y < map->height
		&& intersection->x >= 0 && intersection->y >= 0)
	{
		// printf("intersection->x: %g\n", intersection->x);
		// printf("intersection->y: %g\n", intersection->y);
		field_index = map->width * (size_t)intersection->y + (size_t)intersection->x;
		if (map->fields[field_index] == FIELD_WALL)
		{
			distance = fabs((engine_state->pos_x - intersection->x)
				/ sin(DEG2RAD(engine_state->ray_angle)));
			break ;
		}
		intersection->x += intersection->step_x;
		intersection->y += intersection->step_y;
	}
	return (distance);
}

double		dist_to_hor_inters(t_engine_state *engine_state, t_intersection *hor_inters, t_map *map)
{
	hor_inters->y = floor(engine_state->pos_y);
	hor_inters->step_y = -TILE_SIZE;
	if (engine_state->ray_angle >= 90 && engine_state->ray_angle < 270)
	{
		hor_inters->y = floor(engine_state->pos_y) + TILE_SIZE;
		hor_inters->step_y = TILE_SIZE;
	}
	hor_inters->x = engine_state->pos_x + fabs((engine_state->pos_y - hor_inters->y)
		* tan(DEG2RAD(engine_state->ray_angle)));
	hor_inters->step_x = TILE_SIZE * fabs(tan(DEG2RAD(engine_state->ray_angle)));
	if (engine_state->ray_angle >= 180 && engine_state->ray_angle < 360)
	{
		hor_inters->x = engine_state->pos_x - fabs((engine_state->pos_y - hor_inters->y)
			* tan(DEG2RAD(engine_state->ray_angle)));
		hor_inters->step_x = -hor_inters->step_x;
	}
	// printf("horiz_x_step: %g\n", hor_inters->step_x);
	// printf("horiz_y_step: %g\n", hor_inters->step_y);
	// printf("hor_inters->x:%g\n", hor_inters->x);
	// printf("hor_inters->y:%g\n", hor_inters->y);
	return (distance_to_wall(hor_inters, engine_state, map));
}

/*
**	find vertical intersection
**  you can see that the distance between xi is the same
**		0°
**    |   | /
** 	  |   |/							if we know the angle
**    |  /|next yi       	90°	 	  as our 0 axis is vertical we measure our angle from vertical 0
**    | / |                         	slope = tan(angle) = width / dist between yi's
**    |/  |              	so: dist between yi = width / tan(angle) where width = TILE_SIZE
**   /|yi
**					 distance between yi = y_step;
** 		180°
**
*/

double		dist_to_ver_inters(t_engine_state *engine_state, t_intersection *vert_inters, t_map *map)
{
	vert_inters->x = floor(engine_state->pos_x) + TILE_SIZE;
	vert_inters->step_x = TILE_SIZE;
	if (engine_state->ray_angle >= 180 && engine_state->ray_angle < 360)
	{
		vert_inters->x -= TILE_SIZE;
		vert_inters->step_x = -vert_inters->step_x;
	}
	vert_inters->y = engine_state->pos_y - fabs((engine_state->pos_x - vert_inters->x)
		/ tan(DEG2RAD(engine_state->ray_angle)));
	vert_inters->step_y = -TILE_SIZE / fabs(tan(DEG2RAD(engine_state->ray_angle)));
	if (engine_state->ray_angle >= 90 && engine_state->ray_angle < 270)
	{
		vert_inters->y = engine_state->pos_y + fabs((engine_state->pos_x - vert_inters->x)
			/ tan(DEG2RAD(engine_state->ray_angle)));
		vert_inters->step_y = -vert_inters->step_y;
	}
	// printf("vert_x_step: %g\n", vert_inters->step_x);
	// printf("vert_y_step: %g\n", vert_inters->step_y);
	// printf("vert_x:%g\n", vert_inters->x);
	// printf("vert_y:%g\n", vert_inters->y);
	return (distance_to_wall(vert_inters, engine_state, map));
}

void		init_intersection_result(t_intersection_result *inters_result)
{
	inters_result->dist_to_wall = 0;
	inters_result->wall_height = 0;
	// inters_result->wall_height = inters_result->dist_to_wall * 500; // temporary result = h in pixels * distance to wall
	inters_result->is_side_wall = 0;
	inters_result->current_texture = NULL;
	inters_result->current_color = 0;
	inters_result->texture_x = 0;
	inters_result->texture_y = 0;
}

void		init_engine_state(t_engine_state *engine_state, t_map *map, t_resolution *resolution)
{
	engine_state->dist_to_plane = (resolution->x / 2.0) / tan(DEG2RAD(FOV / 2.0));
	engine_state->pos_x = map->start_pos_x + 0.5;
	engine_state->pos_y = map->start_pos_y + 0.5;
	engine_state->ray_angle = map->start_direction;
}

//remove this function!
// void		print_data(t_engine_state *engine_state,
// 	t_intersection_result *inters_result, t_map *map)
// {

// 	// printf("ray angle: %g\n", engine_state->ray_angle);
// 	// printf("pos_x: %g\n", engine_state->pos_x);
// 	// printf("pos_y: %g\n", engine_state->pos_y);
// 	// printf("dist_horiz: %g\n", inters_result->dist_to_wall);
// }

double		wrap_angle(double angle)
{
	while (angle < 0.0)
		angle += 360.0;
	while (angle > 360.0)
		angle -= 360.0;
	return (angle);
}


void	check_plane_size(void *mlx, t_resolution *resolution)
{
	int 	sizex;
	int		sizey;

	mlx_get_screen_size(mlx, &sizex, &sizey);
	if (resolution->x > sizex || resolution->y > sizey)
	{
		resolution->x = sizex;
		resolution->y = sizey;
	}
}

t_window		start_window(t_window *window, t_resolution *resolution)
{
	window->mlx = mlx_init();
	// if (window->mlx == NULL)   !!! correct  this!
	// {
	// 	// return (report_error("Failed to connect to the graphical system"));
	// 	return ; // should retuen an error 
	// }
	check_plane_size(window->mlx, resolution);
	window->mlx_win = mlx_new_window(window->mlx, resolution->x, resolution->y, "cub3D");
	window->img = mlx_new_image(window->mlx, resolution->x, resolution->y);
	window->address = mlx_get_data_addr(window->img, &window->bits_per_pixel, &window->line_length,
		&window->endian);
	// my_mlx_pixel_put(&data, 50, 50, 0x0000FF00);
	return (*window);
}


void		render_scene(t_map *map, t_style *style)
{
	t_window				window;
	t_engine_state			engine_state;
	t_intersection			intersection;
	t_intersection_result	inters_result;
	double					dist_hor_inters;
	double					dist_ver_inters;
	int						i;
	double					start_ray_angle;

	init_engine_state(&engine_state, map, &style->resolution);
	init_intersection_result(&inters_result);
	window = start_window(&window, &style->resolution); // how to return error here?
	i = 0;
	start_ray_angle = engine_state.ray_angle;
	while (i < style->resolution.x)
	{
		inters_result.is_side_wall = 0; // I probably don't need it in structure, unless I move this functionality to another place
		engine_state.ray_angle = start_ray_angle + RAD2DEG(atan((i - style->resolution.x / 2.0)
			/ engine_state.dist_to_plane)));
			engine_state.ray_angle = wrap_angle(engine_state.ray_angle);
			dist_hor_inters = dist_to_hor_inters(&engine_state, &intersection, map);
			dist_ver_inters = dist_to_ver_inters(&engine_state, &intersection, map);
			if (dist_ver_inters < dist_hor_inters)
			{
				inters_result.is_side_wall = 1;
				if (intersection.step_x < 0) // if it's a west wall
					inters_result.current_color = 0x00FFFFFF;
				else
					inters_result.current_color = 0x00FF0000;
				//define texture coordinates, define texture path
				inters_result.dist_to_wall = dist_ver_inters;
			}
			else
			{
				inters_result.dist_to_wall = dist_hor_inters;
				if (intersection.step_y < 0) //south wall
					inters_result.current_color = 0x0000FF00;
				else
					inters_result.current_color = 0x000000FF;
				//define texture coordinates, define texture path
			}
			inters_result.wall_height = TILE_SIZE / inters_result.dist_to_wall * engine_state.dist_to_plane;
			draw_vertical_line(&window, &inters_result, &style->resolution, &i);
			i++;
	}
	draw_image(&window);
}
