/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:16:39 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/15 18:15:39 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*Start the execution, we handle the signals during the execution,
	then we setup redirections */
void	executor(t_data *data)
{
	signal_in_exec();
	// setup_redirections(data->redirections);
	// setup_heredoc(data->redirections);
	if (data->pipex == 0)
		launch_single_cmd(data->struc_cmd, data);
	else
	 	launch_pipes(data);
	/*Here we have to check the stuff with the pipes,
		because we have multiple cmd,
		i Will test with one command because is easie
	and the we can test for multiple commands*/
}
