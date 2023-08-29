/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:51:54 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/29 14:21:20 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipes(int num_pipes, int **pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		if (pipe(pipes[i]) == -1)
			error_msg("Error creating pipe\n");
		i++;
	}
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

void	execute_pipes(t_cmd *cmds, int num_pipes, int **pipes, t_data *data)
{
	int	status;
	int	*pid;
	int	i;

	i = 0;
	status = 0;
	pid = (int *)malloc((data->pipex + 1) * sizeof(int));
	while (cmds && i <= num_pipes)
	{
		setup_heredoc(data, cmds->redirections);
		pid[i] = fork();
		if (pid[i] == -1)
			error_msg("Error creating process\n");
		else if (pid[i] == 0)
		{
			child_pipe(i, num_pipes, pipes);
			execute_cmd(cmds, data);
		}
		else
			close_pipes(i, num_pipes, pipes);
		i++;
		cmds = cmds->next;
	}
	wait_pids(num_pipes, pid, status);
	free(pid);
}

void	launch_pipes(t_data *data)
{
	int		i;
	int		**pipes;
	t_cmd	*cmds;

	i = 0;
	pipes = (int **)malloc(data->pipex * sizeof(int *));
	while (i < data->pipex)
	{
		pipes[i] = (int *)malloc(2 * sizeof(int));
		i++;
	}
	signal_in_exec();
	cmds = data->struc_cmd;
	create_pipes(data->pipex, pipes);
	execute_pipes(cmds, data->pipex, pipes, data);
	i = 0;
	while (i < data->pipex)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}
