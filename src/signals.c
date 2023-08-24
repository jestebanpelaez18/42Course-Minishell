/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:37:14 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/24 16:26:08 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putendl_fd("", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}
void	start_signal(void)
{
	if (signal(SIGINT, handler) == SIG_ERR)
		error_msg("Signal error");
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		error_msg("Signal error");
}

static void	fork_signal(int signal)
{
	if (signal == SIGQUIT)
	{
		kill(-2, signal);
		ft_putendl_fd("Quit: 3", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 1);
		g_var.g_exit_status = 131;
	}
	if (signal == SIGINT)
	{
		ft_putendl_fd("", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 1);
	}
}

void	signal_in_exec(void)
{
	if (signal(SIGQUIT, fork_signal) == SIG_ERR)
		error_msg("Signal error");
	if (signal(SIGINT, fork_signal) == SIG_ERR)
		error_msg("Signal error");
}

void	heredoc_signal(void)
{
	if (signal(SIGINT, hd_handler) == SIG_ERR)
		error_msg("Signal error");
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		error_msg("Signal error");
}
