/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:51:54 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/04 11:53:03 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_single_cmd(t_cmd *cmds, t_redirec *redirec, t_data *data)
{
}

int	pipesforrealz(t_cmd *cmds, t_redirec *redirec, t_data *data)
{
	int	pipes[data->pipex + 1]
	int	i;
	int	j;
	int	x;
	
	i = 0;
	while (i < data->pipex + 1)
	{
		if (pipe(pipes[i]) == -1)
		{
			printf("Error creating pipe\n");
			return (1);
		}
	}
	i = 0;
	j = 0;
	while (i < data->pipex)
	{
		pids[i] = fork();
		if (pids[i] == -1)
		{
			printf("Error creating process\n");
			return (2);
		}
		if (pids[i] == 0)
		{//child process
			while (j < data->pipex + 1)
			{//close all except the read and write of current
				if (i != j)
					close(pipes[j][0]);
				if (i + 1 != j)
					close(pipes[j][1]);
				j++;
			}
			if (read(pipes[i][0]), &x, sizeof(int) == -1)
			{//read the variable
				printf("Error at reading\n");
				return (3);
			}
			/* do something to the variable here! */
			if (write(pipes[i + 1][1]) == -1)
			{//write into next pipe
				printf("Error at writing\n");
				return (4);
			}
			close(pipes[i][0]);
			close(pipes[i + 1][1]);
			return (0);
		}
	}
	//main process
	i = 0;
	while (i < data->pipex)
	{
		wait(NULL);
		i++;
	}
	return (0);
}

int	mult_pipes(t_cmd *cmds, t_redirec *redirec, t_data *data)
{
	int	fd[3][2];
	int	i;
	int	pid1;
	int	pid2;
	int	/* variable */;
	/* char* variable? */
	
	while (i < 3)
	{
		if (pipe(fd[i]) < 0)
		{
			close_all_fd(); //create function where all fd's are closed
			return (1);
		}
		i++;
	}
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{//child process 1
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);
		if (read(fd[0][0], &/* variable */, sizeof(/* variable */)))
			return (3);
		//apply function here to variable
		if (write(fd[1][1] &/* variable */, sizeof(/* variable */)))
			return (4);
		close(fd[0][0]);
		close(fd[1][1]);
		return (0);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (5);
	if (pid2 == 0)
	{//child process 2
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		close(fd[2][0]);
		if (read(fd[1][0], &/* variable */, sizeof(/* variable */)))
			return (6);
		//apply function here to variable
		if (write(fd[2][1] &/* variable */, sizeof(/* variable */)))
			return (7);
		close(fd[1][0]);
		close(fd[2][1]);
		return (0);
	}
	//parent process
	close(fd[0][0]);
	close(fd[1][0]);
	close(fd[1][1]);
	close(fd[2][1]);
	if (write(fd[01], /* variable */, sizeof(/* variable */)))
		return (8);
	if (read(fd[2][0], &x, sizeof(int)) < 0)
		return (9);
	printf("result /* variable */\n");
	close(fd[0][1]);
	close(fd[2][0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

//takes the first command and pipes it into the second
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
		//if built-in:
		// built-in();
		//else
		// execve(/*/bin/ execute */,cmds, NULL);
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
		//if built-in:
		// built-in();
		//else
		// execve(/*/bin/ execute */,cmds, NULL);
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
