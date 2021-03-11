/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   report_error.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 12:48:04 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/11 18:48:15 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPORT_ERROR_H
# define REPORT_ERROR_H

# define ERROR 0
# define ANSI_COLOR_YELLOW  "\e[33m"
# define ANSI_BOLD_BLACK "\e[1;37m"
# define ANSI_COLOR_RESET   "\e[0m"

int		report_error_with_line(int line_num, char *message);
int		report_error(char *message);
#endif