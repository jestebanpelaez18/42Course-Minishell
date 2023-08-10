/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:51:54 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/10 13:44:06 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipes(t_data *data, int pipes)
{
	int	i;

	i = 0;
	while (i < data->pipex + 1)
	{
		if (pipe(pipes[i]) == -1)
			error_msg("Error creating pipe\n");
		i++;
	}
}

void	close_all_fd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->pipex + 1)
	{//close all except the read and write of current
		close(pipes[j][0]);
		close(pipes[j][1]);
		i++;
	}
}

int	piper(int data)
{
	int pids[data->pipex];
	int	pipes[data->pipex + 1][2];
	int	i;
	
	i = 0;
	create_pipes(data, pipes);
	while (i < data->pipex)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			error_msg("Error creating process\n");
		if (pids[i] == 0)
		{//child process
			close_all_fd(data);
			if (i > 0)
			{
				if (dup2(pipes[i][0], STDIN_FILENO) == -1)
			//receive the variable from last pipe
					error_msg("Error at dup\n");
			}
			if (dup2(pipes[i + 1][1], STDOUT_FILENO) == -1)
			//write the variable into the next pipe
					error_msg("Error at dup\n");
			/* do something to the variable here! */
			// if built-in -> which builtin -> run builtin()
			//if execve
			execve(/bin/echo, echo, 0)
			return (0);
		}
	}
	//main process
	close_all_fd(data);
	i = 0;
	while (i < data->pipex)
	{
		waitpid(pids[i],&y ,0); //&=addres of random int variable necessary for cathing errors etc. and other return values (signals etc).
		i++;
	}
	return (0);
	
}

void	executor(t_data *data)
{
	t_pid *pid;
	int status;

	signal_in_exec();
	data->struc_cmd = expander(data, data->struc_cmd);
	pid = data->struc_pid;
	pid->id = fork();
	if (pid->id == 0)
	{
		if (data->pipex == 0)
		piper(data->struc_cmd, data->redirections, data);
			//launch_single_cmd(data->struc_cmd, data->redirections, data);
		// else
		// 	pipes
		/*Here we have to check the stuff with the pipes,
		because we have multiple cmd,
		i Will test with one command because is easie
	and the we can test for multiple commands*/
	}
	else if (pid->id < 0)
		perror("fork");
	else
		pid->wid = waitpid(pid->id, &status, WUNTRACED);
}
