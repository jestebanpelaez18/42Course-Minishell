/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:23:16 by rrask             #+#    #+#             */
/*   Updated: 2023/08/30 15:47:20 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	envdup_plusone(t_data *data)
{
	char	**env_copy;
	int		len;
	int		i;

	len = 0;
	while (data->env[len] != NULL)
		len++;
	env_copy = malloc(sizeof(char *) * (len + 2));
	if (!env_copy)
		return ;
	i = 0;
	while (data->env[i] != NULL)
	{
		env_copy[i] = ft_strdup(data->env[i]);
		i++;
	}
	env_copy[len] = NULL;
	env_copy[len + 1] = NULL;
	free(data->env);
	data->env = NULL;
	data->env = env_copy;
}

/*Matches the key in the environment, and returns the position.
If it does not exist, it creates it and locates it.*/
int	match_env_key(char *arg, t_data *data, int index, int len)
{
	int		i;

	if (!arg || !data->env)
		return (-1);
	i = index;
	while ((data->env[i]) && ft_strncmp(arg, data->env[i], len) != 0)
		i++;
	if (data->env[i] == '\0')
		envdup_plusone(data);
	return (i);
}

char	*get_string(char *arg)
{
	char	*str;
	int		start;
	int		len;
	int		i;

	start = 0;
	i = 0;
	if (!arg)
		return (NULL);
	while (arg[start] && arg[start] != '=')
		start++;
	start++;
	len = (int)ft_strlen(arg) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (start < (int)ft_strlen(arg))
	{
		str[i] = arg[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_key(char *arg)
{
	char	*str;
	int		end;
	int		i;

	end = 0;
	i = 0;
	while (arg[end] && arg[end] != '=')
		end++;
	end++;
	str = malloc(sizeof(char) * end + 1);
	if (!str)
		return (NULL);
	while (i < end)
	{
		str[i] = arg[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*combine_str(const char *str, const char *key)
{
	const int	len1 = ft_strlen(key);
	const int	len2 = ft_strlen(str);
	const int	final_size = len1 + len2 + 3;
	char *const	new = ft_calloc(sizeof(char), final_size);

	ft_strlcat(new, key, final_size);
	ft_strlcat(new, str, final_size);
	return (new);
}
