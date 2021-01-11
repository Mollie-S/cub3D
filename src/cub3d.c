/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 22:11:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/11 22:12:02 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "mlx.h"

int		main(int argc, char **argv)
{
	void	*connection_identifier;
	void	*mlx_win;

	if (argv[2])
	{
		write(1, "--save", 6);
	}

	if (argc < 2)
	{
		write(1, "Please, enter a valid map name", 30);
		return (1);
	}
	connection_identifier = mlx_init();
	if (connection_identifier == NULL)
	{
		write(1, "Failed to connect to the graphical system", 41);
		return (1);
	}
	mlx_win = mlx_new_window(connection_identifier, 1920, 1080, "Hello world!");
	mlx_loop(connection_identifier);

	return (0);
}
