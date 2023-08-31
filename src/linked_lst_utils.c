/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:02:33 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/31 14:22:07 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnew(char *token, int type, int index)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (node == NULL)
		return (NULL);
	node->tokens = token;
	node->type = type;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_token	*ft_lstlast(t_token *lst)
{
	t_token	*current;

	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*last;
	t_token	*bottom;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	bottom = ft_lstlast(last);
	bottom->next = new;
	new->prev = bottom;
}
