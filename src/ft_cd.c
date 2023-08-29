/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:45:40 by rrask             #+#    #+#             */
/*   Updated: 2023/08/29 17:30:55 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_msg_cd(char *msg, char *input)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(input, 2);
	ft_putendl_fd(" no such file or directory", 2);
}

void	update_path(char *key, char *path, char **env)
{
	int		pos;
	char	*match_key;

	pos = 0;
	match_key = get_key(key);
	pos = match_env_key(match_key, env, 0, ft_keylen(match_key));
	env[pos] = combine_str(path, match_key);
}

int	ft_cd(char **args, char **env)
{
	char	cwd[PATH_MAX];
	char	*cur_path;

	if (!args[1])
		return (0);
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
	update_path("OLDPWD=", cur_path, env);
	update_path("PWD=", getcwd(cwd, PATH_MAX), env);
	return (0);
}
