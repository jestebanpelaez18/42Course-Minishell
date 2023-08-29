/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:45:40 by rrask             #+#    #+#             */
/*   Updated: 2023/08/29 16:48:10 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_export_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
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

	cur_path = getcwd(cwd, PATH_MAX);
	if (chdir(args[1]) == -1)
		perror("cd: Failed to change directory.");
	update_path("OLDPWD=", cur_path, env);
	update_path("PWD=", getcwd(cwd, PATH_MAX), env);
	return (1);
}
