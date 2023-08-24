/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:52 by rrask             #+#    #+#             */
/*   Updated: 2023/08/24 17:29:31 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Get environment.
2. Add variables to the end of the list.
3. If the variable exists: rewrite it with the given argument.

EDGECASE: Handle every argument after export.
*/

#include "../inc/minishell.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

static	int	get_env_var(char *arg, char **env, int index, int len)
{
	int	i;

	if (!arg || !*env)
		return (-1);
	i = index;
	while (env[i] && ft_strncmp(arg, env[i], len))
		i++;
	if (env[i] == '\0')
		return (0);
	return (i);
}

static	int	is_first_alpha(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !*arg)
		return (0);
	if (!((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z')))
		return (-1);
	while ((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z'))
		i++;
	return (1);
}

void	ft_free_array(char **arr)
{
	if (!arr || !*arr)
		return ;
	while (arr)
	{
		free(*arr);
		arr++;
	}
}

static void	print_export_env(char **env)
{
	char	**export;
	int		i;

	export = envdup(env);
	// if (!export)
	// 	return ;
	i = 0;
	while (export[i])
	{
		if (export[i][0] != '\0')
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(export[i], 1);
			ft_putchar_fd('\n', 1);
		}
		i++;
	}
	ft_free_array(export);  // A function that frees the whole array.
}

static char **modify_env_var(char **env, char *arg, \
							int eq_flag, int key_flag)
{
	int i;
	int len;
	int pos;
	char *tmp;
	
	len = ft_strlen(arg);
	tmp = NULL;
	i = 0;
	if (eq_flag == 0 && key_flag == 1)
		return (env);
	else if (eq_flag == 1 && key_flag == 1)
	{
		pos = get_env_var(arg, env, i, len);
		tmp = env[pos];
		// free(env[pos]);
		env[pos] = strdup(arg);
		env[pos] = ft_strjoin(env[pos], ""); //How 2 get "" into stringjoin
		// printf("%s\n", env[pos]);
	}
	//printf("Change value of the key.");
	else if (eq_flag == 0 && key_flag == 0)
	{
		while(env[i] != '\0')
			i++;
		env[i] = ft_strdup(arg);
	}
	else if (eq_flag == 1 && key_flag == 0)
		printf("Make the key, and give it the value.");
	return (env);
}

static char	**ft_export(char *arg, char **env)
{
	int	index;
	int	len;
	int	eq_flag;
	int	key_flag;

	(void)env;
	if (!arg || !*arg)
		return (NULL);
	index = 0;
	eq_flag = 0;
	key_flag = 0;
	len = ft_strlen(arg);
	if (is_first_alpha(arg) == 1)
	{
		if (arg[len - 1] == '=')
			eq_flag = 1;
		if (get_env_var(arg, env, index, len))
			key_flag = 1;
		env = modify_env_var(env, arg, eq_flag, key_flag);
	}
	else
	{
		ft_putstr_fd("export: ", 2);
		ft_putstr_fd("'", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("'", 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
	}
	return (env);
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	len;

	(void)argc;
	i = 1;
	len = 0;
	if (!argv || (argv[i] && (ft_strncmp(argv[i], "export", 7) != 0)))
		return (-1);
	i++;
	if (argv[i])
	{
		while (argv[i])
		{
			ft_export(argv[i], env);
			i++;
		}
	}
	else
	{
		i = 0;
		while (env[i])
			print_export_env(env);
	}
	return (0);
}
