/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:25:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/31 20:03:53 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_node(char *sub_line, t_token **tokens, int operator)
{
	t_token	*node;
	static int index = 0;

	node = ft_lstnew(sub_line, operator, ++index);
	if (!node)
		return (0);
	ft_lstadd_back(tokens, node);
	return (1);
}

int	tok_operator(char *line, int i, t_token **tokens)
{
	char	operator;

	operator = operator_type(line[i]);
	if (operator == RIGH_R && operator_type(line[i + 1]) == RIGH_R)
	{
		if (!create_node(NULL, tokens, APPEND))
			error_msg("allocation error");
		return (2);
	}
	else if (operator== LEFT_R && operator_type(line[i + 1]) == LEFT_R)
	{
		if (!create_node(NULL, tokens, HEREDOC))
			error_msg("allocation error");
		return (2);
	}
	else if (operator)
	{
		if (!create_node(NULL, tokens, operator))
			error_msg("allocation error");
		return (1);
	}
	return (0);
}

int	tok_word(char *line, int i, t_token **tokens)
{
	int	j;

	j = 0;
	while (line[i + j] != '\0' && !check_token_type(line[i + j]))
	{
		j += tok_closed_quotes(line, i, '\'');
		j += tok_closed_quotes(line, i, '\"');
		if (check_delimiter(line[i + j], " \f\n\r\t\v"))
			break ;
		j++;
	}
	if (!create_node(ft_substr(line, i, j), tokens, WORD))
		error_msg("allocation error");
	return (j);
}

void	tokenization(t_data *data)
{
	int	i;

	i = 0;
	while (data->line_read[i])
	{
		i += is_whitespace(data->line_read, i);
		if (check_token_type(data->line_read[i]))
			i += tok_operator(data->line_read, i, &data->struc_tok);
		else
			i += tok_word(data->line_read, i, &data->struc_tok);
	}
	// printList(data->struc_tok);
	// data->struc_tok = expander(data, data->struc_cmd);
}
