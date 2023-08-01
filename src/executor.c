/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:51:54 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/31 19:02:51 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_single_cmd(t_cmd *cmds, t_redirec *redirec, t_data *data)
{
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
		// 	launch_multiple_cmd
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
