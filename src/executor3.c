/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:04:19 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/25 17:23:44 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_path(char **env)
{
	int		i;
	char	*temp_env;

	i = 0;
	temp_env = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			temp_env = env[i] + 5;
			break ;
		}
		i++;
	}
	return (temp_env);
}

static char	*copy_exec_path(char *directory, char *cmds)
{
	char	*temp_exec;
	char	*temp2_exec;
	char	*temp3_exec;

	temp_exec = ft_strdup(directory);
	temp2_exec = ft_strjoin(temp_exec, "/");
	free(temp_exec);
	temp3_exec = ft_strjoin(temp2_exec, cmds);
	free(temp2_exec);
	return (temp3_exec);
}

char	*executable_path(char **commands, t_data *data)
{
	char	*path_exec;
	char	**directories;
	char	**envp;
	int		j;

	if (!commands || !commands[0])
		return (NULL);
	j = 0;
	envp = data->env;
	directories = ft_split(copy_path(envp), ':');
	while (directories[j])
	{
		path_exec = copy_exec_path(directories[j], commands[0]);
		if (access(path_exec, X_OK) == 0)
		{
			free_argt(directories);
			return (path_exec);
		}
		j++;
		free(path_exec);
	}
	free_argt(directories);
	return (NULL);
}
