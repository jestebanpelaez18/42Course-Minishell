/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:46:31 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/18 17:47:28 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putendl_fd("", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
        g_var.heredoc_signal = 1;
	}
}