/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 22:11:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/05 15:56:36 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // needed for system( function, remove)

#include "mlx.h"
#include "data.h"
#include "read_map.h"
#include "style.h"
#include "map.h"
#include "report_error.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char *dst;
	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		start_mlx(t_resolution *resolution)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		return (report_error("Failed to connect to the graphical system"));
	}
	check_plane_size(mlx, resolution);
	mlx_win = mlx_new_window(mlx, resolution->x, resolution->y, "cub3D");
	data.img = mlx_new_image(mlx, resolution->x, resolution->y);
	data.address = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
		&data.endian);
	my_mlx_pixel_put(&data, 50, 50, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);

	return (1);
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

int		main(int argc, char **argv)
{
	t_style  style;
	t_map	 map;

	if (argv[2])
	{
		write(1, "--save", 6);
	}
	if (argc < 2)
	{
		perror("Please, enter a valid map name");
		return (1);
	}
	if (argc > 2)
	{
		perror("Only one map is allowed!");
		return (1);
	}
	init_map_style(&style);
	init_map(&map);
	if (!parse_cub_map(argv[1], &style, &map))
	{
		return (1);
	}
	if (!start_mlx(&style.resolution))
	{
		write(1, "Error.\n", 7);
		return (1);
	}
	// check if every mallocced line is freed
	debug_print_map(&map); // remove this function!!! 
	debug_print_style(&style);// remove this function!!! 

	free_map_style(&style);
	free_map(&map);
	// all structures freed?
	return (0);
}


//  check that if screen_size is more than resolution.x and y. it must be adapted to the screen size
//you get screen_size  from mlx_get_screen_size()
