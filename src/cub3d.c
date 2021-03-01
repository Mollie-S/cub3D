/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 22:11:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 18:03:26 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //do I need it here?
#include <unistd.h>
#include <stdlib.h> // needed for system( function, remove)

#include "read_map.h"
#include "game_engine/game_loop.h"
#include "window.h"
#include "style.h"
#include "map.h"
#include "report_error.h"
#include "result.h"

int	check_arguments(int argc, char **argv)
{
	if (argv[1] == NULL)
		return(report_error("Incorrect filename."));
	if (argc < 2)
		return(report_error("Invalid map name."));
	if (argc > 3)
		return(report_error("Too many arguments specified."));
	if (argc == 3 && ft_strncmp("--save", argv[2], 7) != 0)
		return(report_error("Incorrect argument for creating a screenshot specified."));
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	t_style		style;
	t_map	 	map;
	t_window	window;
	int			screenshot;

	if (!check_arguments(argc, argv))
		return(1);
	screenshot = FALSE;
	if (argc == 3)
		screenshot = TRUE;
	init_map_style(&style);
	init_map(&map);
	if (!parse_cub_map(argv[1], &style, &map))
	{
		return (1);
	}
	if (!start_window(&window, &style.resolution))
		return (1);
	if (!game_loop(&window, &style, &map, screenshot))
		return (1);
	// check if every mallocced line is freed
	// debug_print_map(&map); // remove this function!!! 
	// debug_print_style(&style);// remove this function!!! 

	// are all these free neded???
	// free_map_style(&style);
	// free_map(&map);
	// free(&window);
	// all structures freed? 
	system("leaks cub3D");
	// debug flags removed in makefile?
	return (0);
}
