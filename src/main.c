/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:41:12 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 15:48:06 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data)
{
	data->pipex = 0;
	data->struc_cmd = NULL;
	data->struc_tok = NULL;
	g_var.heredoc_signal = 0;
}

void	get_env(t_data *data, char **env)
{
	data->env = envdup(env);
}

void	get_line(t_data *data)
{
	data->line_read = readline("minishell> ");
	if (!data->line_read)
		error_msg("exit");
	if (data->line_read || *data->line_read)
		add_history(data->line_read);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argv;
	if (argc > 1)
		error_msg("No arguments for minishell");
	init_data(&data);
	get_env(&data, env);
	g_var.g_exit_status = 0;
	while (42)
	{
		start_signal();
		get_line(&data);
		if (check_line(&data, data.line_read) == 1)
		{
			tokenization(&data);
			parser(&data);
			executor(&data);
			reset(&data);
		}
		init_data(&data);
	}
	return (0);
}
