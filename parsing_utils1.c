/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:46:51 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/13 19:01:46 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_number_of_pipes(t_data *data, t_token *tokens)
{
	t_token *node;

	node = tokens;
	while (node->next != NULL)
	{
		if (node->type == PIPE)
			data->pipex++;
		node = node->next;
	}
    printf("%d \n", data->pipex);
}