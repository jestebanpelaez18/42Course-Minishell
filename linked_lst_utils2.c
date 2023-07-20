/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:39:22 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/20 17:34:31 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_new(char **cmd)
{
	t_cmd	*node;

	node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->commands = cmd;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_cmd	*cmd_last(t_cmd *lst)
{
	t_cmd	*current;

	current = lst;
	while (current != NULL)
		current = current->next;
	return (current);
}

void	cmd_add_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;
	t_cmd	*bottom;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	bottom = cmd_last(last);
	bottom->next = new;
	new->prev = bottom;
}

int	create_cmd_node(char **sub_line, t_cmd **cmds)
{
	t_cmd	*node;

	(void)cmds;
	node = cmd_new(sub_line);
	if (!node)
		return (0);
	// cmd_add_back(cmds, node);
	return (1);
}

void	deleteNode(t_token **struck_tok, char *str)
{
	t_token *temp;
	t_token *prev;

	temp = *struck_tok;
	if (temp != NULL && temp->tokens == str)
	{
		*struck_tok = temp->next;
		if(temp->tokens)
		{
			free(temp->tokens);
			temp->tokens = NULL;
		}
		free(temp);
		temp = NULL;
		printf("%s\n","perra");
		
		return ;
	}
	printf("%s\n","perraza");
	while (temp != NULL && temp->tokens != str)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp);
}