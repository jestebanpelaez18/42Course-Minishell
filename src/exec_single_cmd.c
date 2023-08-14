/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:17:58 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/14 15:43:57 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_execution(t_cmd *cmds, char *path, t_data *data)
{
	if (access(cmds->commands[0], F_OK) == 0)
		execve(cmds->commands[0], cmds->commands, data->env);
	else
		execve(path, cmds->commands, data->env);
	return (0);
}

int	get_path(t_cmd *cmds, t_data *data)
{
	char	*path;

	cmds->commands = separete_args(cmds->commands);
     
	path = executable_path(cmds->commands, data);
	if (path)
	{
		if (!do_execution(cmds, path, data))
		{
			error_msg_command("Command not found: ", cmds->commands[0]);
			g_exit_status = 127;
		}
		free(path);
	}
	else
	{
		error_msg_command("Command not found: ", cmds->commands[0]);
		g_exit_status = 127;
	}
	return (g_exit_status);
}
  
/*Now this is the final part of the executing,
this command will work for single command and pipex,
is basically the last step. So here we are gonna check if our command is a
built in,
if that is the case we run our built in. In other case execve will take care
of that,
	and for that case we have to search for the executable in the directories specified by the PATH environment variable. 
The PATH variable is a colon-separated list of directories where the shell searches for executables. For example,
if PATH is /usr/bin:/bin:/usr/local/bin,
the shell will search these directories for the executable file corresponding to the command.*/

void	execute_cmd(t_cmd *cmds, t_data *data)
{
	int	exit_status;

	exit_status = 0;
	// if(is_builtin)
	// {
	//
	// }
	// else
	exit_status = get_path(cmds, data);
	//exit(exit_status);
}
/*Here we launch single cmd, we check if the built in is an enviroment comand,
	it means
that affects or modify our enviroment, if that is the case,
	we have to run the program
in the parent procces,
	because in that way we will keep the changes in our minishell,
in other case we execure our program whit execvp or built in if is the case */

void	launch_single_cmd(t_cmd *cmds, t_data *data)
{
	int pid;
	int status;

	// if (envp_cmd(data))
	// {
	// 	// Run built in
	// 	// come back to minishell loop, basically we finish the execution
	// }
	// data->struc_pid = NULL;
    // pid = data->struc_pid;
	pid = fork();
	if (pid == 0)
		execute_cmd(cmds, data);
	else if (pid < 0)
		perror("fork");
	waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
}
