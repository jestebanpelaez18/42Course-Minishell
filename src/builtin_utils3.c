/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:19:31 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/26 19:23:43 by jpelaez-         ###   ########.fr       */
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
		while (arr[j])
		{
			if (cmd_cmp(cmds[i], arr[j]))
				e_s = run_cmd(cmds, j + 3, data);
			j++;
		}
		i++;
	}
	return (e_s);
}
