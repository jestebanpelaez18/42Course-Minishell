/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:51:54 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/22 19:58:12 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipes(int num_pipes, int (*pipes)[2])
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

void	close_unused_pipes(int num_pipes, int (*pipes)[2], int current_pipe)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		if (i != current_pipe)
		{
			close(pipes[i][0]);
			close(pipes[i + 1][1]);
		}
		i++;
	}
}

void	execute_pipes(t_cmd *cmds, int num_pipes, int (*pipes)[2], t_data *data)
{
	int	status;
	int	pid[data->pipex + 1];
	int	i;

	i = 0;
	while (cmds && i <= num_pipes)
	{
		setup_heredoc(data, cmds->redirections);
		pid[i] = fork();
		if (pid[i] == -1)
			error_msg("Error creating process\n");
		else if (pid[i] == 0)
		{
			close_unused_pipes(num_pipes, pipes, i);
			if (i < num_pipes)
			{
				dup2(pipes[i][1], STDOUT_FILENO);
				close(pipes[i][1]);
			}
			if (i > 0)
			{
				dup2(pipes[i - 1][0], STDIN_FILENO); // Read from previous pipe
				close(pipes[i - 1][0]);
			}
			execute_cmd(cmds, data);
		}
		else
			close(pipes[i][1]); // Close write end of current pipe
		i++;
		cmds = cmds ->next;
	}
	i = 0;
	while (i <= num_pipes)
	{
		waitpid(pid[i], &status, 0);
		g_var.g_exit_status = WEXITSTATUS(status);
		i++;
	}
}

void	launch_pipes(t_data *data)
{
	int		i;
	int		pipes[data->pipex][2];
	t_cmd	*cmds;

	i = 0; 
	signal_in_exec();
	cmds = data->struc_cmd;
	create_pipes(data->pipex, pipes);
	execute_pipes(cmds, data->pipex, pipes, data);
	while (i < data->pipex)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}
