/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 22:11:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/13 12:21:28 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "mlx.h"
#include "data.h"

typedef struct		s_data
{
	void    *img;
	char    *address;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}               	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char *dst;
	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;

	if (argv[2])
	{
		write(1, "--save", 6);
	}

	if (argc < 1)
	{
		write(1, "Please, enter a valid map name", 30);
		return (1);
	}
	mlx = mlx_init();
	if (mlx == NULL)
	{
		write(1, "Failed to connect to the graphical system", 41);
		return (1);
	}
	mlx_win = mlx_new_window(mlx, 500, 500, "cub3D");
	data.img = mlx_new_image(mlx, 500, 500);
	data.bits_per_pixel = 16;
	data.line_length = 100;
	data.address = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
		&data.endian);
	my_mlx_pixel_put(&data, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);

	while (1);
	return (0);
}
