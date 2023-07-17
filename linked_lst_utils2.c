/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:39:22 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/17 18:45:38 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_new(char **token)
{
	t_cmd	*node;

	node = (t_cmd *)malloc(sizeof(t_cmd));
	if (node == NULL)
		return (NULL);
	node->commands = token;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_cmd	*cmd_last(t_cmd *lst)
{
	t_cmd	*current;

	current = lst;
	while (current->next != NULL)
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

int	create_cmd_node(char **sub_line, t_cmd **commands)
{
	t_cmd	*node;

	node = cmd_new(sub_line);
	if (!node)
		return (0);
	cmd_add_back(commands, node);
	return (1);
}
