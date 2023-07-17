/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:07:32 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/17 16:26:37 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*initiate_cmd(t_token *token)
{
	char	**cmd;
	int		len;

	len = count_commands(token);
	cmd = (char **)malloc(sizeof(char *) * (len + 1));
	if (!cmd)
		error_msg("allocation error");
	
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
