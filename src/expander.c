/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:03:01 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/31 20:04:06 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**check_expander(t_data *data, char **commands)
{
	int	i;

	i = 0;
	while (commands[i])
	{
        if(commands[i])
	}
}

t_cmd	*expander(t_data *data, t_cmd *cmds)
{
	cmds->commands = check_expander(data, cmds->commands);

	return (cmds);
}