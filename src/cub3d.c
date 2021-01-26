/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 22:11:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/26 11:44:27 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// #include "mlx.h"
// #include "data.h"
#include "read_map.h"
#include "style.h"
#include "map.h"


// void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
// {
// 	char *dst;
// 	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int		start_mlx()
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	data;

// 	mlx = mlx_init();
// 	if (mlx == NULL)
// 	{
// 		write(1, "Failed to connect to the graphical system", 41);
// 		return (0);
// 	}
// 	mlx_win = mlx_new_window(mlx, 500, 500, "cub3D");
// 	data.img = mlx_new_image(mlx, 500, 500);
// 	data.address = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
// 		&data.endian);
// 	my_mlx_pixel_put(&data, 50, 50, 0x0000FF00);
// 	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (1);
// }

int		main(int argc, char **argv)
{
	t_style  style;
	t_map	 map;

	if (argv[2])
	{
		write(1, "--save", 6);
	}

	if (argc < 1)
	{
		write(1, "Please, enter a valid map name", 30);
		return (1);
	}
	init_map_style(&style);
	init_maze_map(&map);
	if (!parse_cub_map(argv[1], &style, &map))
	{
		return (1);
	}

	// if (!start_mlx())
	// {
	// 	write(1, "Error.\n", 7);
	// 	return (1);
	// }
	// check if every mallocced line is freed
	free_map_style(&style);
	free_maze_map(&map);
	// all structures freed? 
	return (0);
}
