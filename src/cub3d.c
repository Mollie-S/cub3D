/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 22:11:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/09 11:36:56 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // needed for system( function, remove)

#include "read_map.h"
#include "game_engine/game_loop.h"
#include "window.h"
#include "style.h"
#include "map.h"

int		main(int argc, char **argv)
{
	t_style		style;
	t_map	 	map;
	t_window	window;

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
	if (!start_window(&window, &style.resolution))
		return (1);
	game_loop(&window, &style, &map);
	// check if every mallocced line is freed
	// debug_print_map(&map); // remove this function!!! 
	// debug_print_style(&style);// remove this function!!! 

	free_map_style(&style);
	free_map(&map);
	free(window.mlx);
	// all structures freed? 
	system("leaks cub3D");
	// debug flags removed in makefile?
	return (0);
}
