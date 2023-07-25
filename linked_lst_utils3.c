/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:07:20 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/25 19:30:47 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	deleteNode(t_token **struck_tok, char *str)
// {
// 	t_token *temp;
// 	t_token *prev;

// 	temp = *struck_tok;
// 	if (temp != NULL && temp->tokens == str)
// 	{
// 		struck_tok = temp->next;
// 		free(temp);
// 		return ;
// 	}
// 	while (temp != NULL && temp->tokens != str)
// 	{
// 		prev = temp;
// 		temp = temp->next;
// 	}
// 	if (temp == NULL)
// 		return ;
// 	prev->next = temp->next;
// 	free(temp);
// }

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
	while (current->next != NULL)
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
