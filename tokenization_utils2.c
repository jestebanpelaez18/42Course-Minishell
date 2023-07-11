/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:49:05 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/11 19:48:52 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_operator handle_single_op(char operator)
{
    if(operator == '>')
		return(RIGH_R);
	else if (operator == '<')
		return(LEFT_R);
	else
		return(PIPE);
	return(0);
}

void printList(t_token *node)
{
    t_token *temp;

	temp = node;
	printf("NULL");
    while (node != NULL)
    {
        printf("%s -> ", node->tokens);
        node = node->next;
    }
    printf("NULL \n\n");
	printf("NULL");
    while (temp != NULL)
    {
        printf("%d -> ", temp->operator);
        temp = temp->next;
    }
    printf("NULL \n");
}