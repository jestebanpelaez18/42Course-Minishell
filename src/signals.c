/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:37:14 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/31 18:53:08 by jpelaez-         ###   ########.fr       */
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

/* initial signals, when shell is interactive*/

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
		ft_putendl_fd("", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 1);
	}
}

void	signal_in_exec(void)
{
	if (signal(SIGQUIT, fork_signal) == SIG_ERR)
		error_msg("Signal error");
}
