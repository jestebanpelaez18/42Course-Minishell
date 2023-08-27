/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:52:33 by rrask             #+#    #+#             */
/*   Updated: 2023/08/27 13:10:01 by jpelaez-         ###   ########.fr       */
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
	int	j;

	j = 0;
	while (e_cpy[index][j])
	{
		e_cpy[index][j] = 0;
		j++;
	}
	return (e_cpy);
}

void	ft_unset(char *cmd, char**env)
{
	char	**e_cpy;
	int		index;
	int		len;

	if (!cmd)
		return ;
	index = 0;
	e_cpy = envdup(env);
	if (!e_cpy)
		return ;
	len = ft_strlen(cmd);
	index = get_env_var(cmd, e_cpy, index, len);
	while (e_cpy[index] && e_cpy[index][len] != '=')
		index = get_env_var(cmd, e_cpy, index + 1, len);
	env = remove_env_var(e_cpy, index);
	free_argt(e_cpy);
}
