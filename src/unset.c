/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:52:33 by rrask             #+#    #+#             */
/*   Updated: 2023/08/13 16:52:39 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "minishell.h"

/*REMOVE FROM FINAL*/
static char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	while (src[len])
	{
		len++;
	}
	dest = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (dest == NULL)
	{
		return (0);
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*REMOVE FROM FINAL*/
static char	**envdup(char **env)
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

/*REMOVE FROM FINAL*/
static int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (str1[i] != '\0' && str2[i] != '\0')
		&& str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

/*REMOVE FROM FINAL*/
static int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_env_var(char *arg, char **env, int index, int len)
{
	int	i;

	if (!arg || !*env)
		return (-1);
	i = index;
	while (env[i] && ft_strncmp(arg, env[i], len))
	{
		i++;
	}
	return (i);
}

char	*match_env_var(char *cmd, char**env)
{
	char	**e_cpy;
	char	*str;
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
	/*Use the index to remove the correct env variable*/
	/*char **remove_env_var(e_cpy, index)*/
	/*Re-allocate the string at the [index] and leave it with only the env var name*/
	/*Difference between env and export is that the unset variables are still viewable by using export, they are merely empty.*/
	/*As in USER=''*/
	str = getenv(e_cpy[index]);
	return (str);
}

int	main(int argc, char **arg, char **env)
{
	char	*str;

	if (argc != 2)
		return (0);
	if (!arg[1])
		return (0);
	str = match_env_var(arg[1], env);
	/*When the match is found, what do*/
	/**/
// 	printf("%s\n", str);
	return (0);
}
