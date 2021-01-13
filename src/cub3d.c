/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 22:11:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/12 19:27:19 by osamara       ########   odam.nl         */
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

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

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
	img.img = mlx_new_image(mlx, 500, 500);
	img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	while (1);
	return (0);
}
