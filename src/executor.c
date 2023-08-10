/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:16:39 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/10 18:30:54 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void do_execution(t_cmd *cmds, char *path, t_data *data)
{
	if(cmds->commands[0] == '/')
	{
		
	}
	else
		execve(cmds->commands[0],cmds->commands, data->env);
	
}
void	get_path(t_cmd *cmds, t_data *data)
{
	char *path;

	cmds->commands = separete_args(cmds->commands);	
	path = executable_path(cmds->commands, data);
	if(path)
	{
		do_execution(cmds, path, data);
		free(path);
	}
	else
	{
		error_msg_command("Command not found: ", cmds->commands[0][0]);
		g_exit_status = 127;
	}
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
	// if(is_builtin)
	// {
	// 	
	// }
	else 
		get_path(cmds, data);
}

/*Here we launch single cmd, we check if the built in is an enviroment comand,
	it means
that affects or modify our enviroment, if that is the case,
	we have to run the program
in the parent procces,
	because in that way we will keep the changes in our minishell,
in other case we execure our program whit execvp or built in if is the case */
void	launch_single_cmd(t_cmd *cmds, t_redirec *redirec, t_data *data)
{
	t_pid	*pid;
	int		status;

	if (envp_cmd(data))
	{
		// Run built in
		// come back to minishell loop, basically we finish the execution
	}
	pid = data->struc_pid;
	pid->id = fork();
	if (pid->id == 0)
		execute_cmd(cmds, data);
	else if (pid->id < 0)
		perror("fork");
	else
		pid->wid = waitpid(pid->id, &status, WUNTRACED);
}

/*Start the execution, we handle the signals during the execution,
	then we setup redirections */
void	executor(t_data *data)
{
	t_pid	*pid;
	int		status;

	signal_in_exec();
	setup_redirections(data->redirections);
	// setup_heredoc(data->redirections);
	if (data->pipex == 0)
		launch_single_cmd(data->struc_cmd, data->redirections, data);
	// else
	// 	pipes(data->struc_cmd, data->redirections, data)
	/*Here we have to check the stuff with the pipes,
		because we have multiple cmd,
		i Will test with one command because is easie
	and the we can test for multiple commands*/
}
