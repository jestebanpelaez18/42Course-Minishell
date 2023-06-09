/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:56:21 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/10 11:41:55 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**envdup(char **env)
{
	char	**env_copy;
	int		len;
	int		i;

	len = 0;
	while (env[len] != NULL)
		len++;
	env_copy = malloc(sizeof(char *) * (len + 1));
	if (!env_copy)
		return (NULL);
	i = 0;
	while (env[i] != NULL)
	{
		env_copy[i] = ft_strdup(env[i]);
		i++;
	}
	env_copy[i] = NULL;
	return (env_copy);
}
