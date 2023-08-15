/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:20 by rrask             #+#    #+#             */
/*   Updated: 2023/08/15 12:56:30 by rrask            ###   ########.fr       */
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
Returns -1 if the str is empty, 0 if no match and 1 if there is a match.*/
int	is_builtin(char *str)
{
	int				i;
	int				flag;
	static char		*arr[3] = {"echo", "unset", "export"};

	if (!str)
		return (-1);
	i = 0;
	flag = 0;
	while (arr[i] && i <= 2)
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

static void	run_cmd(char *cmd, int index)
{
	if (index == 0)
	{
		ft_echo(&cmd);
	}
	else if (index == 1)
		printf("Unset my heart...\n");
	else if (index == 2)
		printf("Exporting T_T\n");
	else
		printf("Nevermind then.\n");
}

/*Depending on what the index is when it finishes, it runs that command.*/
void	run_builtin(char **cmds)
{
	static char		*arr[3] = {"echo", "unset", "export"};
	int				i;
	int				j;

	if (!cmds)
		return ;
	i = 0;
	while (cmds[i])
	{
		j = 0;
		while (arr[j])
		{
			if (cmd_cmp(cmds[i], arr[j]))
				run_cmd(cmds[i], j);
			j++;
		}
		i++;
	}
}
