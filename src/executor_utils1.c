/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:46:26 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/23 18:05:14 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	envp_cmd(t_data *data)
// {
// // 	if (builint == cd)
// // 		return (1);
// // 	if (builint == env)
// // 		return (1);
// // 	if (builint == export)
// // 		return (1);
// //     if (builint == pwd)
// // 		return (1);
// //     if (builint == unset)
// // 		return (1);
// //     return(0);
// }

static char	*undo_split(char **commands, char *n_str)
{
	char	*temp;
	char	*space;
	int		i;

	if (!commands || !commands[0])
		return (NULL);
	temp = ft_strdup(commands[0]);
	i = 1;
	while (commands[i])
	{
		n_str = temp;
		space = ft_strjoin(n_str, " ");
		free(n_str);
		temp = ft_strjoin(space, commands[i]);
		free(space);
		i++;
	}
	n_str = temp;
	return (n_str);
}

char	**separete_args(char **str)
{
	char	**temp;
	char	*split_join;

	split_join = undo_split(str, NULL);
	if (str)
		free_argt(str);
	temp = ft_split(split_join, ' ');
	if (split_join)
		free(split_join);
	split_join = undo_split(temp, NULL);
	if (temp)
		free_argt(temp);
	temp = ft_split(split_join, ' ');
	if (split_join)
		free(split_join);
	return (temp);
}
