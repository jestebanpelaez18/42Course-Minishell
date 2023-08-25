/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:54:31 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/25 16:49:06 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_redirect(t_redirec **tokens)
{
	t_redirec	*temp;

	if (!tokens || !*tokens)
		return ;
	while (*tokens)
	{
		// printf("%d hello \n ",(*tokens)->type);
		temp = (*tokens);
		*tokens = (*tokens)->next;
		if (temp->type == HEREDOC)
			unlink(temp->hd_file_name);
		if (temp->token)
			free(temp->token);
		free(temp);
	}
	*tokens = NULL;
}

void	reset_token(t_token **tokens)
{
	t_token	*temp;

	if (!tokens || !*tokens)
		return ;
	while (*tokens)
	{
		temp = *tokens;
		(*tokens) = (*tokens)->next;
		if (temp->tokens)
			free(temp->tokens);
		free(temp);
	}
	*tokens = NULL;
}

void	reset_cmds(t_cmd **struc_cmd)
{
	t_cmd	*temp;

	if (!(*struc_cmd))
		return ;
	while (*struc_cmd)
	{
		temp = (*struc_cmd);
		*struc_cmd = (*struc_cmd)->next;
		if (temp->commands)
			free_argt(temp->commands);
		if (temp->redirections)
			reset_redirect(&temp->redirections);
		free(temp);
	}
	*struc_cmd = NULL;
}

void	reset(t_data *data)
{
	if (data->struc_cmd)
		reset_cmds(&data->struc_cmd);
	if (data->struc_tok)
		reset_token(&data->struc_tok);
	// if (data->line_read)
	// 	free(data->line_read);
	return ;
}
