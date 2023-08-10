/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:51:54 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/10 16:25:00 by nvan-den         ###   ########.fr       */
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

void	close_all_fd(int num_pipes, int (*pipes)[2], int current_pipe)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{//close all except the read and write of current
		if (i != current_pipe)
		{
			close(pipes[i][0]);
			close(pipes[i][1]);
		}
		i++;
	}
}

int	execute_pipes(t_cmd *cmds, int num_pipes, int (*pipes)[2], int current_pipe)
{
	int pids[data->pipex + 1];
	int	pipes[data->pipex + 1][2];
	int	i;
	int	error;
	
	i = 0;
	redirec = NULL;//
	cmds = NULL;//
	create_pipes(data->pipex + 1, pipes);
	while (i < data->pipex)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			error_msg("Error creating process\n");
		if (pids[i] == 0)
		{//child process
			close_all_fd(data->pipex + 1, pipes, i);
			if (i > 0)
			{
				if (dup2(pipes[i - 1][0], STDIN_FILENO) == -1)
			//receive the variable from last pipe
					error_msg("Error at dup read\n");
				close(pipes[i][0]);
			}
			if (i < data->pipex)
			{
				if (dup2(pipes[i][1], STDOUT_FILENO) == -1)
				//write the variable into the next pipe
						error_msg("Error at dup write\n");
			}
			/* do something to the variable here! */
			// if built-in -> which builtin -> run builtin()
			//if execve
			printf("hi\n");
			char *argv[] = {"echo hi\n", NULL};
			execvp("echo", argv);
			error_msg("Error executing command\n");
		}
		i++;
	}
	//main process
	close_all_fd(data->pipex + 1, pipes, -1);
	i = 0;
	while (i < data->pipex + 1)
	{
		waitpid(pids[i],&error ,0); //&=addres of random int variable necessary for cathing errors etc. and other return values (signals etc).
		i++;
	}
	return (0);
	
}

void	executor(t_data *data)
{
	int	i;
	int pipes[data->pipex][2];
	
	i = 0;
	signal_in_exec();
	//data->struc_cmd = expander(data, data->struc_cmd);
	create_pipes_recursive(data->pipex, pipes, 0);
	execute_pipes(data->struc_cmd, data->pipex, pipes, 0);
	while (i < data->pipex);
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
	}
}
