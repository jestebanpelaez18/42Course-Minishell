/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:07:32 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/27 18:07:54 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printcmd(t_cmd *node)
{
	int	i;

	i = 0;
	while (node)
	{
		while (node->commands[i] != NULL)
		{
			printf("%s-> ", node->commands[i]);
			i++;
		}
		printf("NULL \n\n");
		i = 0;
		node = node->next;
	}
}

t_cmd	*initiate_cmd(t_token *node)
{
	t_cmd	*temp;
	t_token	*tok_temp;
	char	**cmd;
	int		len;
	int		i;

	len = count_commands(node);
	cmd = (char **)malloc(sizeof(char *) * (len + 1));
	if (!cmd)
		error_msg("allocation error");
	i = 0;
	tok_temp = node;
	while ((tok_temp && tok_temp->type != PIPE))
	{
		if (tok_temp->tokens)
		{
			cmd[i] = ft_strdup(tok_temp->tokens);
			i++;
		}
		tok_temp = tok_temp->next;
	}
	cmd[i] = NULL;
	temp = cmd_new(cmd);
	return (temp);
}

void	fill_commands(t_token *data, t_cmd **cmds, t_redirec *redirections)
{
	t_token	*node;
	t_cmd	*cmd;

	node = data;
	while (node)
	{
		node = next_elem(node);
		parse_redirection(node, &redirections);
		if (!node)
			break ;
		cmd = initiate_cmd(node);
		if (!cmd)
			error_msg("allocation error");
		cmd_add_back(cmds, cmd);
	}
}

t_cmd	*start_firts_cmd(t_token *data, t_redirec **redirec)
{
	t_cmd	*cmd;
	
	(void)redirec;
	cmd = NULL;
	cmd = initiate_cmd(data);
	if (!cmd)
		return (NULL);
	return (cmd);
}

void	parser(t_data *data)
{
	set_number_of_pipes(data, data->struc_tok);
	parse_redirection(data->struc_tok, &data->redirections);
	// printList(data->struc_tok);
	data->struc_cmd = NULL;
	data->struc_cmd = start_firts_cmd(data->struc_tok, &data->redirections);
	if (!data->struc_cmd)
		error_msg("allocation error");
	fill_commands(data->struc_tok, &data->struc_cmd, data->redirections);
	printcmd(data->struc_cmd);
	// parse_redirection(node);
}
