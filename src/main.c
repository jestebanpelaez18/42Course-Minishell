/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:41:12 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/04 18:50:47 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data, char **env)
{
	data->env = envdup(env);
	g_exit_status = 1;
	data->pipex = 0;
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
	t_data data;

	(void)argv;
	if (argc > 1)
		error_msg("No arguments for minishell");
	// if(!env || (*env))
	//     error_msg("No enviroment");
	// for (char **envp = env; *envp != 0; envp++)
	// {
	//     char *thisEnv = *envp;
	//     printf("%s\n", thisEnv);
	// 	break ;
	// }
	init_data(&data, env);
	while (42)
	{
		start_signal();
		get_line(&data);
		if (check_line(&data, data.line_read) == 1)
		{
			tokenization(&data);
			parser(&data);
			// executor(&data);
			// do parsing, execute...
		}
		// free(&data.line_read);
	}
	return (0);
}