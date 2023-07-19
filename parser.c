/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:07:32 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/19 18:35:31 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printcmd(t_cmd *node)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (node->commands[i])
	{
		printf("%s-> ", node->commands[i]);
		i++;
	}
	printf("NULL \n\n");
}

t_cmd	*initiate_cmd(t_token *node)
{
	t_cmd	*temp;
	t_token	*tok_temp;
	char	**cmd;
	int		len;
	int		i;

	tok_temp = node;
	len = count_commands(tok_temp);
	cmd = (char **)malloc(sizeof(char *) * (len + 1));
	if (!cmd)
		error_msg("allocation error");
	i = 0;
	while (len != 0)
	{
		cmd[i] = ft_strdup(node->tokens);
		node = node->next;
		i++;
		len--;
	}
	cmd[i] = NULL;
	temp = cmd_new(cmd);
	return (temp);
}

int	fill_commands(t_data *data, t_cmd **cmds)
{
	t_token	*node;
	t_cmd	*cmd;

	node = data->tokens;
	while (node != NULL)
	{
		cmd = initiate_cmd(node);
		if (!cmd)
			return (0);
		cmd_add_back(cmds, cmd);
		node = node->next;
	}
	return (1);
}

t_cmd	*start_firts_cmd(t_data *data)
{
	t_token	*tok_node;
	t_cmd	*cmd;

	cmd = NULL;
	tok_node = data->struc_tok;
	cmd = initiate_cmd(tok_node);
	if (!cmd)
		return (NULL);
	return (cmd);
}

void	parser(t_data *data)
{
	set_number_of_pipes(data, data->struc_tok);
	data->struc_cmd = NULL;
	data->struc_cmd = start_firts_cmd(data);
	if (!data->struc_cmd)
		error_msg("allocation error");
	// delete the nodes in the token for next iterations
	if (!fill_commands(data, &data->struc_cmd))
		error_msg("allocation error");
	// printcmd(data->struc_cmd);
}

/*Have to check the error when y copy the firts command,
	the other functions are working pretty good*/