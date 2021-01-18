

#include <stdio.h>

#include <unistd.h>

#include "../mlx/mlx.h"
// #include "data.h"

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

void	draw_rectangle(t_data *data, int horizontal, int vertical, unsigned int color, int win_length, int win_height)
{
    int y = vertical;
    unsigned blue = 0;
    unsigned green = 0;
    unsigned red = 0;

    while (y <= win_height - vertical)
    {
        int x = horizontal;
        color = ((red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF);
        blue += 1;
        // red += 5;
        while (x <= win_length - horizontal)
        {
            my_mlx_pixel_put(data, x, y, color);
            x++;
        }
        y++;
        // green += 1;
    }
}

int		main(int argc, char **argv)
{
    void	*mlx;
    void	*mlx_win;
    t_data	data;
    int     win_length = 500;
    int     win_height = 500;

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
    mlx_win = mlx_new_window(mlx, win_length, win_height, "cub3D");
    data.img = mlx_new_image(mlx, win_length, win_height);
    data.address = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
        &data.endian);
    draw_rectangle(&data, 50, 50, 0x0000FF00, win_length, win_height);
    mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
    mlx_loop(mlx);

    while (1);
    return (0);
}
