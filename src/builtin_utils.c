/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:20 by rrask             #+#    #+#             */
/*   Updated: 2023/09/01 12:45:58 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_cmp(const char *str1, const char *str2)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	if (!str1 || !str2)
		return (0);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 != len2)
		return (0);
	while (i < len2 && (str1[i] != '\0' && str2[i] != '\0')
		&& str1[i] == str2[i])
	{
		i++;
	}
	if (i == len2)
		return (1);
	return (0);
}

int	is_builtin(char *str)
{
	int				i;
	int				flag;
	static char		*arr[7] = {"echo", "pwd", "env", "export", \
								"unset", "exit", "cd"};

	i = 0;
	flag = 0;
	while (i < 7)
	{
		if (cmd_cmp(str, arr[i]) == 1)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

int	run_cmd(char **cmd, int index, t_data *data)
{
	int	exit_s;
	int	i;

	exit_s = 0;
	i = 0;
	if (index == 0)
		exit_s = ft_echo(cmd);
	else if (index == 1)
		exit_s = ft_pwd();
	else if (index == 2)
		ft_env(data->env);
	else if (index == 3)
		exit_s = ft_export(cmd, data);
	else if (index == 4)
	{
		while (cmd[i++])
			data->env = ft_unset(cmd[i], data->env);
	}
	else if (index == 5)
		exit_s = ft_exit(data, cmd);
	else if (index == 6)
		exit_s = ft_cd(cmd, data);
	return (exit_s);
}

int	run_builtin(t_data *data, char **cmds)
{
	static char		*arr[7] = {"echo", "pwd", "env", "export", \
								"unset", "exit", "cd"};
	int				j;
	int				e_s;

	j = 0;
	e_s = 0;
	while (j < 7)
	{
		if (cmd_cmp(cmds[0], arr[j]))
		{
			e_s = run_cmd(cmds, j, data);
			break ;
		}
		j++;
	}
	return (e_s);
}
