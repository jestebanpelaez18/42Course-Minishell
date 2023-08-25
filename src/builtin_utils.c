/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:20 by rrask             #+#    #+#             */
/*   Updated: 2023/08/25 20:16:01 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	cmd_cmp(const char *str1, const char *str2)
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

/*Compares if the given command is from a list of builtins or not.
Returns -1 if the str is empty, 0 if no match and 1 if there is a match.
echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit with no options*/
int	is_builtin(char *str)
{
	int				i;
	int				flag;
	static char		*arr[7] = {"cd", "pwd", "env", "exit", \
								"echo", "unset", "export"};

	i = 0;
	flag = 0;
	while (arr[i])
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

static int	run_cmd(char **cmd, int index)
{
	int	exit_s;

	exit_s = 0;
	if (index == 0)
		exit_s = ft_echo(cmd);
	else if (index == 1)
		exit_s = ft_pwd();
	else if (index == 2)
		printf("Exporting T_T\n");
	else
		printf("Nevermind then.\n");
	return (exit_s);
}

int	run_builtin(char **cmds)
{
	static char		*arr[7] = {"echo", "pwd", "env", "exit", \
								"cd", "unset", "export"};
	int				i;
	int				j;
	int				e_s;

	i = 0;
	while (cmds[i])
	{
		j = 0;
		while (arr[j])
		{
			if (cmd_cmp(cmds[i], arr[j]))
				e_s = run_cmd(cmds, j);
			j++;
		}
		i++;
	}
	return (e_s);
}
