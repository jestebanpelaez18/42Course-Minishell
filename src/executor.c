/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:51:54 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/01 15:35:57 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_single_cmd(t_cmd *cmds, t_redirec *redirec, t_data *data)
{
}

int	pipes(t_cmd *cmds, t_redirec *redirec, t_data *data)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{//child process 1
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		//Execute function
		//execve(/*/bin/ execute */,cmds, NULL);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (3);
	if (pid2 == 0)
	{//child process 2
		dup2(fd[1], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		//Execute function
		//execve(/*/bin/ execute */,cmds, NULL);
	}
	close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
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
			launch_single_cmd(data->struc_cmd, data->redirections, data);
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
