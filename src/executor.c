/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:16:39 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 11:56:10 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executor(t_data *data)
{
	signal_in_exec();
	if (data->pipex == 0)
		launch_single_cmd(data->struc_cmd, data);
	else
		launch_pipes(data);
	return ;
}
