/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:07:32 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/20 17:30:40 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printcmd(t_cmd *node)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (node->commands[i] != NULL)
	{
		printf("%s-> ", node->commands[i]);
		i++;
	}
	printf("NULLO \n\n");
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
		cmd[i] = ft_strdup(tok_temp->tokens);
		deleteNode(&node, tok_temp->tokens);
		tok_temp = node;
		i++;
		len--;
	}
	cmd[i] = NULL;
	temp = cmd_new(cmd);
	return (temp);
}

// int	fill_commands(t_data *data, t_cmd **cmds)
// {
// 	t_token	*node;
// 	t_cmd	*cmd;

// 	node = data->struc_tok;
// 	while (node->next != NULL)
// 	{
// 		node = node->next;
// 		cmd = initiate_cmd(node);
// 		if (!cmd)
// 			return (0);
// 		printf("%s\n", "hello");
// 		cmd_add_back(cmds, cmd);
// 	}
// 	return (1);
// }

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
	// if (!fill_commands(data, &data->struc_cmd))
	// 	error_msg("allocation error");
	printcmd(data->struc_cmd);
	printf("%s\n", "helsinki");
	printList(data->struc_tok);
}

/*Have to check the error when y copy the firts command,
	the other functions are working pretty good*/