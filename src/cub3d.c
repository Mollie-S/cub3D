/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 22:11:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/30 17:27:13 by osamara       ########   odam.nl         */
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

int		start_mlx(t_resolution *start_resolution)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	int 	sizex;
	int		sizey;
	int 	x;
	int		y;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		return (report_error("Failed to connect to the graphical system"));
	}
	mlx_get_screen_size(mlx, &sizex, &sizey);
	if (start_resolution->x > sizex || start_resolution->y > sizey)
	{
		x = sizex;
		y = sizey;
	}
	else
	{
		x = start_resolution->x;
		y = start_resolution->y;
	}

	mlx_win = mlx_new_window(mlx, x, y, "cub3D");
	data.img = mlx_new_image(mlx, 500, 500);
	data.address = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
		&data.endian);
	my_mlx_pixel_put(&data, 50, 50, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);

	return (1);
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
	if (!start_mlx(&style.start_resolution))
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
