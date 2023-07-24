/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:46:51 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/24 15:44:06 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_number_of_pipes(t_data *data, t_token *tokens)
{
	t_token	*node;

	node = tokens;
	while (node->next != NULL)
	{
		if (node->type == PIPE)
			data->pipex++;
		node = node->next;
	}
}

int	count_commands(t_token *node)
{
	int	i;
	t_token *temp;

	i = 0;
	temp = node;
	while (temp && temp->type != PIPE)
	{
		if(temp->type == WORD)
			i++;
		temp = temp->next;
	}
	return (i);
}

t_token *next_elem(t_token *args)
{
	t_token	*next_elem;

	next_elem = args;
	while (next_elem)
	{
		if (!next_elem->next)
			return(NULL);
		next_elem = next_elem->next;
		if (next_elem->prev && next_elem->prev->type == PIPE)
			break ;
	}
	return(next_elem);
}