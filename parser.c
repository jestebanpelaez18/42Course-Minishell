/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:07:32 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/18 19:10:20 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printcmd(t_cmd *node)
{
	int		i;
	int 	j;

	i = 0;
	j = 0;
	printf("%s \n", node->commands[2]);
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
	if (!create_cmd_node(cmd, &temp))
		error_msg("allocation error");
	return (temp);
}

// int	fill_commands(t_data *data, t_token *tokens)
// {
// 	t_token	*node;
// 	t_cmd	*cmd;

// 	node = tokens;
// 	while (node != NULL)
// 	{
// 		cmd = initiate_cmd(node);
// 		if (!cmd)
// 			return (NULL);
// 		node = node->next;
// 	}
// 	return (cmd);
// }

int	start_firts_cmd(t_data *data, t_cmd **command)
{
	t_token	*tok_node;
	t_cmd	*cmd;

	tok_node = data->struc_tok;
	cmd = *command;
	cmd = initiate_cmd(tok_node);
	if (!cmd)
		return(0);
	return(1);
}

void	parser(t_data *data)
{
	t_cmd *hello;
	char **str;
	
	set_number_of_pipes(data, data->struc_tok);
	data->struc_cmd = NULL;
	if(!start_firts_cmd(data, &data->struc_cmd))
		error_msg("allocation err");
	//start_commands(data, data->struc_tok);
	if (!data->struc_cmd)
		error_msg("allocation error");
	hello = data->struc_cmd;
	str = hello->commands;
	printf("%s\n", " soy ");
	printf("%s \n", str[0]);
	// printcmd(data->struc_cmd);
	// del node
	// fill_commands()
}



/*Have to check the error when y copy the firts command, the other functions are working pretty good*/