/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   report_error.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 12:48:04 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/28 13:40:12 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPORT_ERROR_H
# define REPORT_ERROR_H

# define ERROR 0

int		report_error_with_line(int line_num, char *message);
int		report_error(char *message);
#endif