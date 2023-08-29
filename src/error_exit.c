/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:03:02 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/29 15:11:24 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error_msg_noexit(char *msg, int exit_status)
{
	ft_putendl_fd(msg, 2);
	g_var.g_exit_status = exit_status;
}

void	error_msg_command(char *msg, char *command)
{
	ft_putstr_fd(command, 2);
	ft_putendl_fd(msg, 2);
}

void	error_msg_redic(char *msg, char *input, int exit_status)
{
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(input, 2);
	g_var.g_exit_status = exit_status;
	exit(EXIT_FAILURE);
}

void	error_msg_parser(t_data *data, char *msg, int type)
{
	ft_putstr_fd(msg, 2);
	if (type == 2)
		ft_putendl_fd(" '<'", 2);
	else if (type == 3)
		ft_putendl_fd(" '>'", 2);
	else if (type == 4)
		ft_putendl_fd(" '<<'", 2);
	else if (type == 5)
		ft_putendl_fd(" '>>'", 2);
	g_var.g_exit_status = 258;
	reset_tools(data);
}
