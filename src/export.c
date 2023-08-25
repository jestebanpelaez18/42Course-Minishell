/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:52 by rrask             #+#    #+#             */
/*   Updated: 2023/08/25 12:48:15 by junheeki         ###   ########.fr       */
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

static	int	match_env_key(char *arg, char **env, int index, int len)
{
	int	i;

	if (!arg || !*env)
		return (-1);
	i = index;
	while ((env[i] != '=') && ft_strncmp(arg, env[i], len) != 0)
		i++;
	if (env[i] == '\0')
		return (0);
	return (i);
}

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
	while (env[i] && ft_strncmp(arg, env[i], len) != 0)
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

static	int	content_check(char *str)	// return 0 -> No Equal, No Value  ex) export USER
{										// return 1 -> Have Equal, No value	ex) export USER=
	int	i;								// return 2 -> Have Equal, with Value ex) export USER=JUN
	int exist_val;

	exist_val = 0;
	i = 0;
	while (str[i] != '=')
		i++;
	printf("str : %c\n", str[i]);
	printf("str : %c\n", str[i + 1]);
	printf("str : %c\n", str[i - 1]);
	if (str[i] == '=')
	{
		exist_val = 1;
		{
		if (str[i + 1] != '\0')
			exist_val = 2;
		}
	}
	return (exist_val);
}

static char **modify_env_var(char **env, char *arg, \
							int eq_flag, int key_flag)
{
	int	i;
	int	j;
	int	len;
	int	pos;
	int value_exist;

	len = ft_strlen(arg);
	i = 0;
	value_exist = content_check(arg);
	printf("%d\n", key_flag);
	printf("%d\n", eq_flag);
	if (eq_flag == 0 && key_flag == 1)
		return (env);
	else if (eq_flag == 1 && key_flag == 1)
	{
		//If there is nothing after the equals sign/
		pos = get_env_var(arg, env, i, len);
		env[pos] = strdup(arg);
		env[pos] = ft_strjoinfree(env[pos], "\"");
		if (value_exist == 2)
			env[pos] = ft_strjoinfree(env[pos], &arg[j]);
		env[pos] = ft_strjoinfree(env[pos], "\"");
		printf("%s\n", env[pos]);
		//else if (something there.)
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
	int	value_exist;

	(void)env;
	if (!arg || !*arg)
		return (NULL);
	index = 0;
	eq_flag = 0;
	key_flag = 0;

	len = ft_strlen(arg);
	if (is_first_alpha(arg) == 1)
	{
		if (content_check(arg) == 1) // MAKE THIS INTO MULTITOOL CHECKER, IF THERE IS AN = in the middle of the string.
			eq_flag = 1;
		if (content_check(arg) == 2)
			eq_flag = 1;
		if (match_env_key(arg, env, index, len))
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
