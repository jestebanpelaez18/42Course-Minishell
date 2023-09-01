/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:19:31 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/01 12:29:10 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_builtin(t_data *data, char **cmds)
{
	static char		*arr[4] = {"export", "unset", "exit", "cd"};
	int				i;
	int				j;
	int				e_s;

	i = 0;
	while (cmds[i])
	{
		j = 0;
		while (j < 4)
		{
			if (cmd_cmp(cmds[i], arr[j]))
			{
				e_s = run_cmd(cmds, j + 3, data);
				break ;
			}
			j++;
		}
		i++;
	}
	return (e_s);
}

int	is_env_builtin(char *str)
{
	int				i;
	int				flag;
	static char		*arr[5] = {"export", "unset", "exit", "cd"};

	i = 0;
	flag = 0;
	while (i < 4)
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
