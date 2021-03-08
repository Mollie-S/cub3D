/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 22:11:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/08 23:10:26 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map/read_map.h"
#include "check_arguments.h"
#include "game_engine/game_loop.h"
#include "window.h"
#include "style.h"
#include "map/map.h"
#include "result.h"

int	main(int argc, char **argv)
{
	t_style		style;
	t_map	 	map;
	t_window	window;
	int			screenshot;

	if (!check_arguments(argc, argv))
		return (1);
	screenshot = FALSE;
	if (argc == 3)
		screenshot = TRUE;
	init_map_style(&style);
	init_map(&map);
	if (!parse_cub_map(argv[1], &style, &map))
	{
		return (1);
	}
	if (!start_window(&window, &style.resolution, screenshot))
		return (1);
	if (!game_loop(&window, &style, &map, screenshot))
		return (1);
	return (0);
}
