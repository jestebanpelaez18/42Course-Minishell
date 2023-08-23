/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:07:20 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/23 16:48:28 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	deletenode(t_token **struck_tok, t_token *del)
{
	if (*struck_tok == NULL || del == NULL)
		return ;
	if (*struck_tok == del)
		*struck_tok = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	del = NULL;
	return ;
}

t_redirec	*redirec_lstnew(char *token, int type)
{
	t_redirec	*node;

	node = (t_redirec *)malloc(sizeof(t_redirec));
	if (node == NULL)
		return (NULL);
	node->token = token;
	node->type = type;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_redirec	*redirec_lstlast(t_redirec *lst)
{
	t_redirec	*current;

	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

void	redirec_lstadd_back(t_redirec **lst, t_redirec *new)
{
	t_redirec	*last;
	t_redirec	*bottom;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	bottom = redirec_lstlast(last);
	bottom->next = new;
	new->prev = bottom;
}
