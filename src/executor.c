/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:16:39 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/14 14:46:30 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*Start the execution, we handle the signals during the execution,
	then we setup redirections */
void	executor(t_data *data)
{
	signal_in_exec();
	setup_redirections(data->redirections);
	// setup_heredoc(data->redirections);
	if (data->pipex == 0)
		launch_single_cmd(data->struc_cmd, data);
	else
		pipes_executor(data);
}
