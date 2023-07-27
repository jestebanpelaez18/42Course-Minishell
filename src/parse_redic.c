/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:43:55 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/27 17:57:35 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printredic(t_redirec *node)
{
	t_redirec	*temp;

	temp = node;
	while (node)
	{
		printf("%s -> ", node->token);
		node = node->next;
	}
	printf("NULL \n\n");
	while (temp)
	{
		printf("%d -> ", temp->type);
		temp = temp->next;
	}
	printf("NULL \n");
}

int	create_redirection(char *sub_line, t_redirec **tokens, int operator)
{
	t_redirec	*node;

	node = redirec_lstnew(sub_line, operator);
	if (!node)
		return (0);
	redirec_lstadd_back(tokens, node);
	return (1);
}

void	create_single_redirection(t_token *token, t_redirec **redirection)
{
	if (!create_redirection(ft_strdup(token->next->tokens), redirection,
			token->type))
		error_msg("allocation error");
	printredic(*redirection);
	deleteNode2(&token->next, token->next);
	deleteNode2(&token, token);
}

void	parse_redirection(t_token *node, t_redirec **redirec)
{
	t_token	*tok_temp;

	tok_temp = node;
	while (tok_temp && tok_temp->type == WORD)
		tok_temp = tok_temp->next;
	if (!tok_temp || tok_temp->type == PIPE)
		return ;
	if (tok_temp->type == LEFT_R || tok_temp->type == RIGH_R
		|| tok_temp->type == HEREDOC || tok_temp->type == APPEND)
		create_single_redirection(tok_temp, redirec);
	// parse_redirection(node, redirec);
}

// void	check_redirection(t_token **node)
// {
// 	t_token	*tok_temp;

// 	tok_temp = *node;
// 	while (tok_temp && tok_temp->type == WORD)
// 		tok_temp = tok_temp->next;
// 	if (!tok_temp || tok_temp->type == PIPE)
// 		return ;
// 	else if (tok_temp->type == LEFT_R || tok_temp->type == RIGH_R
// 		|| tok_temp->type == HEREDOC || tok_temp->type == APPEND)
// 	{
// 			printf("%s\n", "hola");
// 	// 	deleteNode(&tok_temp, tok_temp->tokens);
// 		deleteNode(&tok_temp->next, tok_temp->next->tokens);
// 	}
// }
