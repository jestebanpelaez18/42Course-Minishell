/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:17:58 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 12:31:07 by jpelaez-         ###   ########.fr       */
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

	if (!cmds->commands[0])
		return (0);
	exit_s = 0;
	// cmds->commands = separete_args(cmds->commands);
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
		error_msg_command(": command not found", cmds->commands[0]);
		exit_s = 127;
	}
	return (exit_s);
}

void	execute_cmd(t_cmd *cmds, t_data *data)
{
	int	exit_status;

	exit_status = 0;
	setup_redirections(cmds->redirections);
	if (is_builtin(cmds->commands[0]))
	{
		exit_status = run_builtin(data, cmds->commands);
		exit(exit_status);
	}
	else
	{
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
