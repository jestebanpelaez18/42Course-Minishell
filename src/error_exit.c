/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:03:02 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/16 19:07:27 by jpelaez-         ###   ########.fr       */
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
	g_exit_status = exit_status;
}

void	error_msg_command(char *msg, char *command)
{
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(command, 2);
}

void	error_msg_redic(char *msg, char *input, int exit_status)
{
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(input, 2);
	g_exit_status = exit_status;
	exit(EXIT_FAILURE);
}