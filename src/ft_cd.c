/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:45:40 by rrask             #+#    #+#             */
/*   Updated: 2023/09/01 12:48:18 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_msg_cd(char *msg, char *input)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(input, 2);
	ft_putendl_fd(" no such file or directory", 2);
}

void	update_path(char *key, char *path, t_data *data)
{
	int		pos;
	char	*match_key;
	char	*new;

	pos = 0;
	match_key = get_key(key);
	if (match_key)
	{
		pos = match_env_key(match_key, data, 0, ft_keylen(match_key));
		new = combine_str(path, match_key);
		free(data->env[pos]);
		data->env[pos] = new;
		free(match_key);
	}
}

char	*handle_empty_cd(char **env)
{
	int		index;
	char	*temp;

	index = 0;
	index = get_env_var("HOME", env, 0, ft_strlen("HOME"));
	temp = get_string(env[index]);
	return (temp);
}

int	ft_cd(char **args, t_data *data)
{
	char	cwd[PATH_MAX];
	char	*cur_path;
	char	*temp;

	if (!args[1])
	{
		temp = handle_empty_cd(data->env);
		chdir(temp);
		free(temp);
		return (0);
	}
	if (args[1] && args[2])
	{
		error_msg_cd("minishell: cd: ", args[1]);
		return (1);
	}
	cur_path = getcwd(cwd, PATH_MAX);
	if (chdir(args[1]) == -1)
	{
		perror("cd");
		return (1);
	}
	update_path("OLDPWD=", cur_path, data);
	update_path("PWD=", getcwd(cwd, PATH_MAX), data);
	return (0);
}
