/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:40:52 by rrask             #+#    #+#             */
/*   Updated: 2023/08/29 16:49:15 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_keylen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '=')
		i++;
	return (i);
}

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
/**/

char	**modify_env_var(char **env, char *arg, int len)
{
	const int	pos = match_env_key(arg, env, 0, len);
	const int	num = content_check(arg);
	const char	*key = get_key(arg);
	const char	*str = get_string(arg);

	if (num == 1)
	{
		env[pos] = ft_strdup(arg);
		env[pos] = ft_strjoinfree(env[pos], "\"\"");
	}
	else if (num == 2)
		env[pos] = combine_str(str, key);
	return (env);
}

char	**handle_args(char *arg, char **env)
{
	int	index;
	int	len;
	int	key_flag;

	if (!arg || !env)
		return (NULL);
	index = 0;
	key_flag = 0;
	len = ft_keylen(arg);
	if (is_first_alpha(arg) == 1)
	{
		if (content_check(arg) == 0)
			return (env);
		env = modify_env_var(env, arg, len);
	}
	return (env);
}

void	ft_export(char **arg, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!arg || (arg[i] && (ft_strncmp(arg[i], "export", 7) != 0)))
		return ;
	i++;
	if (arg[i])
	{
		while (arg[i])
		{
			env = handle_args(arg[i], env);
			i++;
		}
	}
	else
		print_export_env(env);
}
