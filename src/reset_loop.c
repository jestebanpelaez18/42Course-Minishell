/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:54:31 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/14 14:48:43 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void reset_redirect(t_redirec **tokens)
{
    t_redirec *temp;

    if(!*tokens)
        return ;
    while(*tokens)
    {
        temp = (*tokens);
        *tokens = (*tokens)->next;
        if(temp->token)
            free(temp->token);
        free(temp);
    }
    *tokens = NULL;
}

void reset_token(t_token **tokens)
{
    t_token *temp;

    if(!*tokens)
        return ;
    while(*tokens)
    {
        temp = (*tokens);
        *tokens = (*tokens)->next;
        if(temp->tokens)
            free(temp->tokens);
        free(temp);
    }
    *tokens = NULL;
}

void reset_cmds(t_cmd **struc_cmd)
{
    t_cmd *temp;

    if(!*struc_cmd)
        return ;
    while(*struc_cmd)
    {
        temp = (*struc_cmd);
        *struc_cmd = (*struc_cmd)->next;
        if(temp->commands)
            free_argt(temp->commands);
        free(temp);
    }
    *struc_cmd = NULL;
}

void reset(t_data *data)
{
    reset_cmds(&data->struc_cmd);
    reset_token(&data->struc_tok);
    reset_redirect(&data->redirections);
    if(data->line_read)
        free(data->line_read);
    return ;
}
