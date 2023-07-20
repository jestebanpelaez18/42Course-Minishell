/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utills3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:07:20 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/20 16:23:15 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	deleteNode(t_token **struck_tok, char *str)
{
	t_token *temp;
	t_token *prev;

	temp = *struck_tok;
	if (temp != NULL && temp->tokens == str)
	{
		struck_tok = temp->next;
		free(temp);
		return ;
	}
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
