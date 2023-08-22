/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:07:32 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/22 19:31:32 by jpelaez-         ###   ########.fr       */
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

t_cmd	*initiate_cmd(t_token *node, t_redirec *redirec)
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
	temp = cmd_new(cmd, redirec);
	return (temp);
}

void	fill_commands(t_token *data, t_cmd **cmds)
{
	t_token		*node;
	t_cmd		*cmd;
	t_redirec	*cmd_redic;

	node = data;
	while (node)
	{
		cmd_redic = NULL;
		node = next_elem(node);
		parse_redirection(&node, &cmd_redic);
		if (!node)
			break ;
		cmd = initiate_cmd(node, cmd_redic);
		if (!cmd)
			error_msg("allocation error");
		cmd_add_back(cmds, cmd);
		if (cmd_redic)
			free(cmd_redic);
	}
}

t_cmd	*start_firts_cmd(t_token *data, t_redirec *redirec)
{
	t_cmd	*cmd;
	t_redirec *cmd_redic;

	(void)redirec;
	cmd = NULL;
	cmd_redic = NULL;
	parse_redirection(&data, &cmd_redic);
	cmd = initiate_cmd(data, cmd_redic);
	if (!cmd)
		return (NULL);
	fill_commands(data, &cmd);
	// free(cmd_redic);
	return (cmd);
}

void	parser(t_data *data)
{
	set_number_of_pipes(data, data->struc_tok);
	data->struc_cmd = start_firts_cmd(data->struc_tok,
			data->redirections);
	if (!data->struc_cmd)
		error_msg("allocation error");
	// fill_commands(data->struc_tok, &data->struc_cmd);
}
