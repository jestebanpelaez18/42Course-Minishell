/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:49:50 by junheeki          #+#    #+#             */
/*   Updated: 2023/08/18 12:53:27 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// with cd functiton, when you change your current dir, you should change
// pwd and oldpwd as well/.

// cd or cd ~ -> $HOME
// cd - -> check $OLDPWD
// if there is two arguments, go to first path
// When you move dir with CD, if there is no OLDPWD then create it.
// cd filename -> ex) cd: not a directory: echo.c
// cd wrongname -> ex) cd: no such file or directory: ech
// char *path; This updates when you go to a new directory. (pwd)
// char *old_path; This equals path before path is updated. (oldpwd)

// int go_to_path(int case, t_data *data)
// {

// }

char	*ft_strdup(const char *src)
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

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (str1[i] != '\0' && str2[i] != '\0')
		&& str1[i] == str2[i])
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	get_env_var(char *arg, char **env, int index, int len)
{
	int	i;

	if (!arg || !*env)
		return (-1);
	i = index;
	while (env[i] && ft_strncmp(arg, env[i], len))
		i++;
	return (i);
}

static char	*match_env_var(char *cmd, char **env)
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
	str = getenv(e_cpy[index]);
	return (str);
}

int	arg_counter(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static	void	go_home(char **env)
{
	char	*path;
	char	*old_path;
	char	*path_to_go;

	path_to_go = match_env_var("HOME", env);
	if (!path_to_go)
		return ;// error_msg("cd: HOME not set");
	if (chdir(path_to_go) == 0)
	{
		path = match_env_var("HOME", env);
		old_path = match_env_var("PWD", env);
		//update env, we can use export here
		printf("Path is: %s\n", path);
		printf("Old path is: %s\n", old_path);
		//WORKS
	}
	else
		printf("Lol shit failed\n");
		// error_msg("cd: Failed to change directory.");
}

static	char	**match_case(char *arg, char **env)
{
	// char	*path;
	// char	*old_path;
	// char	*path_to_go;
	int		len;

	if (!arg || !env)
		return (NULL);
	len = ft_strlen(arg);
	if (ft_strncmp(arg, ".", len) == 0)
		go_home(env);
	else if (ft_strncmp(arg, "..", len) == 0)
		printf("DotDot\n");
	else if (ft_strncmp(arg, "~", len) == 0)
		printf("TILDE\n");
	else if (ft_strncmp(arg, "-", len) == 0) // cd: OLDPWD not set || show previous OLDPWD
		printf("Previous OLDPWD\n");
	else if (chdir(arg) == 0)
		printf("Successful path\n");
	return (env);
}

int	ft_cd(char **args, char **env)
{
	int		cd_ret;
	int		argc;

	argc = arg_counter(args);
	cd_ret = 0;
	if (argc == 1)
		go_home(env);
	else
	{
		/*
			Match the different cases with args[1].
				. && .. can be sent to chdir and it works for some reason lol
			If args[1] is a absolute path, ???
			if there is two arguments, go to first path
			When you move dir with CD, if there is no OLDPWD then create it.
			cd filename -> ex) cd: not a directory: echo.c
			cd wrongname -> ex) cd: no such file or directory: ech

			cd_ret should return -1 if it fails.
			
			//;
		*/
		env = match_case(args[1], env);
	}
	return (cd_ret);
}

int	main(int argc, char **arg, char **env)
{
	(void)argc;
	ft_cd(arg, env);
	return (0);
}

/*
TODO LIST

1. Failcheck chdir in match_case
2. Implement export to change the environment variables.

// cd filename -> ex) cd: not a directory: echo.c
// cd wrongname -> ex) cd: no such file or directory: ech
*/