/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:51:54 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/14 13:28:49 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_command(int pipe_read_end, int pipe_write_end, t_cmd *cmd, t_data *data)
{
	int	exit_status;
	
	exit_status = 0;
    dup2(pipe_read_end, STDIN_FILENO);
    dup2(pipe_write_end, STDOUT_FILENO);
	cmd = NULL;
	// if(is_builtin)
	// {
	// 	
	// }
	// else 
    // Execute the command
    // char *argv[] = {"/bin/echo", "echo", NULL};
    // execvp("/bin/echo", argv);	
	exit_status = get_path(cmd, data);
    // If execvp fails, print an error message
    perror("Error executing command");
    exit(exit_status);
}


void	executor(t_data *data)
{
	int	i;
	int pipes[data->pipex][2];
	
	i = 0;
	signal_in_exec();
	//data->struc_cmd = expander(data, data->struc_cmd);
	create_pipes(data->pipex, pipes);
	execute_pipes(data->struc_cmd, data->pipex, pipes, data);
	while (i < data->pipex)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}
