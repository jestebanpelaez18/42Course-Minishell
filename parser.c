/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:07:32 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/17 19:11:51 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*initiate_cmd(t_token *node)
{
	t_cmd	*temp;
	char	**cmd;
	int		len;
	int		i;

	len = count_commands(node);
	cmd = (char **)malloc(sizeof(char *) * (len + 1));
	if (!cmd)
		error_msg("allocation error");
	i = 0;
	while (len != 0)
	{
		cmd[i] = node->tokens;
		node = node->next;
		i++;
		len--;
	}
	if (!create_cmd_node(cmd, &temp))
		error_msg("allocation error");
	return (cmd);
}

t_cmd	*start_commands(t_data *data, t_token *tokens)
{
	t_token	*node;
	t_cmd	*cmd;

	node = tokens;
	while (node != NULL)
	{
		cmd = initiate_cmd(node);
		if (!cmd)
			return (NULL);
		node = node->next;
	}
}

void	parser(t_data *data)
{
	set_number_of_pipes(data, data->struc_tok);
	data->struc_cmd = start_commands(data, data->struc_tok);
	if (!data->struc_cmd)
		return ;
}
