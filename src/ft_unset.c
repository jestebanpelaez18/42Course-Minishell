/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:52:33 by rrask             #+#    #+#             */
/*   Updated: 2023/08/28 13:25:09 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	get_env_var(char *arg, char **env, int index, int len)
{
	int	i;

	if (!arg || !*env)
		return (-1);
	i = index;
	while (env[i] && ft_strncmp(arg, env[i], len))
		i++;
	return (i);
}

static	char	**remove_env_var(char **e_cpy, int index)
{
	char	*last;
	int		i;

	last = NULL;
	i = 0;
	free(e_cpy[index]);
	while (e_cpy[index + 1])
	{
		e_cpy[index] = e_cpy[index + 1];
		index++;
	}
	e_cpy[index] = NULL;
	return (e_cpy);
}

char	**ft_unset(char *cmd, char**env)
{
	char	**e_cpy;
	int		index;
	int		len;

	if (!cmd)
		return (env);
	index = 0;
	e_cpy = envdup(env);
	if (!e_cpy)
		return (env);
	len = ft_strlen(cmd);
	index = get_env_var(cmd, e_cpy, index, len);
	while (e_cpy[index] && e_cpy[index][len] != '=')
		index = get_env_var(cmd, e_cpy, index + 1, len);
	env = remove_env_var(e_cpy, index);
	return (env);
}
