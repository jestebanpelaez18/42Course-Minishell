/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:43:55 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/24 19:47:53 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parse_redirection(t_token *node)
{
    t_token *tok_temp;

    tok_temp = node;
    while(tok_temp && tok_temp == WORD)
        tok_temp = tok_temp->next;
    if(!tok_temp || tok_temp == PIPE)
        return ;
}