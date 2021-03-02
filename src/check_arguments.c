/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_arguments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 20:04:15 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 20:11:44 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check_arguments.h"
#include "result.h"
#include "report_error.h"

#include "libft.h"

#include <unistd.h>

int	check_arguments(int argc, char **argv)
{
	if (argv[1] == NULL)
		return (report_error("Incorrect filename."));
	if (argc < 2)
		return (report_error("Invalid map name."));
	if (argc > 3)
		return (report_error("Too many arguments specified."));
	if (argc == 3 && ft_strncmp("--save", argv[2], 7) != 0)
		return (report_error("Incorrect argument for creating a screenshot."));
	return (SUCCESS);
}
