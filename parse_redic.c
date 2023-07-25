/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:43:55 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/25 19:59:22 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	create_redirection(char *sub_line, t_redirec **tokens, int operator)
// {
// 	t_redirec	*node;

// 	node = redirec_lstnew(sub_line, operator);
// 	if (!node)
// 		return (0);
// 	redirec_lstadd_back(tokens, node);
// 	return (1);
// }

// void	create_single_redirection(t_token *token, t_redirec **redirection)
// {
// 	if (!create_redirection(ft_strdup(token->next->tokens), redirection,
// 			token->type))
// 		error_msg("allocation error");
// 	printredic(*redirection);
// }

// void	parse_redirection(t_token *node)
// {
// 	t_token		*tok_temp;
// 	t_redirec	**new_redireccion;

// 	tok_temp = node;
// 	while (tok_temp && tok_temp->type == WORD)
// 		tok_temp = tok_temp->next;
// 	if (!tok_temp || tok_temp->type == PIPE)
// 		return ;
// 	if (tok_temp->type == LEFT_R || tok_temp->type == RIGH_R
// 		|| tok_temp->type == HEREDOC || tok_temp->type == APPEND)
// 		create_single_redirection(tok_temp, new_redireccion);
// 	parse_redirection(node);
// }

t_token	*check_redirection(t_token *node)
{
	t_token	*tok_temp;

	tok_temp = node;
	while (tok_temp && tok_temp->type == WORD)
		tok_temp = tok_temp->next;
	if (!tok_temp || tok_temp->type == PIPE)
		return (node);
	// else if (tok_temp->type == LEFT_R || tok_temp->type == RIGH_R
	// 	|| tok_temp->type == HEREDOC || tok_temp->type == APPEND)
	return (tok_temp);
}
