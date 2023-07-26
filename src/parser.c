/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:07:32 by jpelaez-          #+#    #+#             */
<<<<<<< HEAD:src/parser.c
/*   Updated: 2023/07/25 20:07:48 by jpelaez-         ###   ########.fr       */
=======
/*   Updated: 2023/07/20 12:36:17 by nvan-den         ###   ########.fr       */
>>>>>>> main:src/parser.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printcmd(t_cmd *node)
{
	int	i;

	i = 0;
<<<<<<< HEAD:src/parser.c
	while (node)
=======
	while (node->commands[i])
>>>>>>> main:src/parser.c
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

<<<<<<< HEAD:src/parser.c
void	fill_commands(t_token *data, t_cmd **cmds)
=======
/* int	fill_commands(t_data *data, t_cmd **cmds)
>>>>>>> main:src/parser.c
{
	t_token	*node;
	t_cmd	*cmd;

<<<<<<< HEAD:src/parser.c
	node = data;
	while (node)
=======
	node = data->tokens; //incompatible pointer types
	while (node != NULL)
>>>>>>> main:src/parser.c
	{
		node = next_elem(node);
		if (!node)
			break ;
		cmd = initiate_cmd(node);
		if (!cmd)
			error_msg("allocation error");
		cmd_add_back(cmds, cmd);
	}
<<<<<<< HEAD:src/parser.c
}
=======
	return (1);
} */
>>>>>>> main:src/parser.c

t_cmd	*start_firts_cmd(t_token *data)
{
	t_cmd	*cmd;

	cmd = NULL;
	cmd = initiate_cmd(data);
	if (!cmd)
		return (NULL);
	return (cmd);
}

void	parser(t_data *data)
{
	set_number_of_pipes(data, data->struc_tok);
	data->struc_cmd = NULL;
	data->struc_cmd = start_firts_cmd(data->struc_tok);
	if (!data->struc_cmd)
		error_msg("allocation error");
<<<<<<< HEAD:src/parser.c
	fill_commands(data->struc_tok, &data->struc_cmd);
	printcmd(data->struc_cmd);
	// parse_redirection(node);
=======
	// delete the nodes in the token for next iterations
/* 	if (!fill_commands(data, &data->struc_cmd))
		error_msg("allocation error"); */
	// printcmd(data->struc_cmd);
>>>>>>> main:src/parser.c
}
