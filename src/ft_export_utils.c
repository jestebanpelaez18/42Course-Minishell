/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:23:16 by rrask             #+#    #+#             */
/*   Updated: 2023/08/26 16:32:44 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	match_env_key(char *arg, char **env, int index, int len)
{
	int	i;

	if (!arg || !*env)
		return (-1);
	i = index;
	while ((env[i]) && ft_strncmp(arg, env[i], len) != 0)
		i++;
	if (env[i] == '\0')
	{
		env[i] = ft_strdup(arg);
		env[i + 1] = NULL;
		match_env_key(arg, env, 0, ft_keylen(arg));
	}
	return (i);
}

char	*get_string(char *arg)
{
	char	*str;
	int		start;
	int		end;
	int		len;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	if (!arg)
		return (NULL);
	while (arg[start] && arg[start] != '=')
		start++;
	start++;
	while (arg[end])
		end++;
	len = end - start;
	str = malloc(sizeof(char) * len + 1);
	while (start < end)
	{
		str[i] = arg[start];
		i++;
		start++;
	}
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
	while (i < end)
	{
		str[i] = arg[i];
		i++;
	}
	return (str);
}

char	*combine_str(const char *str, const char *key)
{
	const int	len1 = ft_strlen(key);
	const int	len2 = ft_strlen(str);
	const int	final_size = len1 + len2 + 3;
	char *const	new = ft_calloc(sizeof(char), final_size);

	ft_strlcat(new, key, final_size);
	ft_strlcat(new, "\"", final_size);
	ft_strlcat(new, str, final_size);
	ft_strlcat(new, "\"", final_size);
	return (new);
}