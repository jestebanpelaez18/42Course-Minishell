/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:17:58 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/28 13:24:45 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_execution(t_cmd *cmds, char *path, t_data *data)
{
	if (access(cmds->commands[0], X_OK) == 0)
		execve(cmds->commands[0], cmds->commands, data->env);
	else
		execve(path, cmds->commands, data->env);
	return (0);
}

int	get_path(t_cmd *cmds, t_data *data)
{
	char	*path;
	int		exit_s;

	exit_s = 0;
	cmds->commands = separete_args(cmds->commands);
	path = executable_path(cmds->commands, data);
	if (path)
	{
		if (!do_execution(cmds, path, data))
		{
			error_msg_command("Command not found: ", cmds->commands[0]);
			exit_s = 127;
		}
		free(path);
	}
	else
	{
		error_msg_command("Command not found: ", cmds->commands[0]);
		exit_s = 127;
	}
	return (exit_s);
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

	// if (!cmds)
	// {
	// 	exit_status = 0;
	// 	exit(exit_status);
	// }
	exit_status = 0;
	setup_redirections(cmds->redirections);
	if (is_builtin(cmds->commands[0]))
	{
		ft_putendl_fd("Our builtin goes here.\n", 2);
		exit_status = run_builtin(data, cmds->commands);
		exit(exit_status);
	}
	else
	{
		// ft_putendl_fd("other", 2);
		exit_status = get_path(cmds, data);
	}
	exit(exit_status);
}

void	launch_single_cmd(t_cmd *cmds, t_data *data)
{
	int	pid;
	int	status;

	if (is_env_builtin(cmds->commands[0]))
	{
		g_var.g_exit_status = env_builtin(data, cmds->commands);
		return ;
	}
	setup_heredoc(data, cmds->redirections);
	pid = fork();
	if (pid == 0)
		execute_cmd(cmds, data);
	else if (pid < 0)
		perror("fork");
	waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
		g_var.g_exit_status = WEXITSTATUS(status);
}
