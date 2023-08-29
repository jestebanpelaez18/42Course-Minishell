/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:18:11 by nvan-den          #+#    #+#             */
/*   Updated: 2023/08/29 14:18:35 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_child_pipes(int num_pipes, int **pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		close(pipes[i][1]);
		close(pipes[i][0]);
		i++;
	}
}

void	child_pipe(int i, int num_pipes, int **pipes)
{
	if (i < num_pipes)
		dup2(pipes[i][1], STDOUT_FILENO);
	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	close_child_pipes(num_pipes, pipes);
}

void	wait_pids(int num_pipes, int *pid, int status)
{
	int	i;

	i = 0;
	while (i <= num_pipes)
	{
		waitpid(pid[i], &status, 0);
		g_var.g_exit_status = WEXITSTATUS(status);
		i++;
	}
}
