/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:52:33 by rrask             #+#    #+#             */
/*   Updated: 2023/08/24 12:06:19 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static	char	**ft_unset(char *cmd, char**env)
{
	char	**e_cpy;
	int		index;
	int		len;

	if (!cmd)
		return (0);
	index = 0;
	e_cpy = envdup(env);
	if (!e_cpy)
		return (NULL);
	len = ft_strlen(cmd);
	index = get_env_var(cmd, e_cpy, index, len);
	while (e_cpy[index] && e_cpy[index][len] != '=')
		index = get_env_var(cmd, e_cpy, index + 1, len);
	e_cpy = remove_env_var(e_cpy, index);
	return (e_cpy);
}
