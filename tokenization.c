/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:25:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/10 16:00:46 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int tok_redirections(char *line, int i, t_token **tokens)
{
	
}
int tok_word(char *line, int i, t_token **tokens)
{
	int j;

	j = 0;
	while(line[i+j] != '\0' && !check_token_type(line[i+j]))
	{
		if(is_white_space(line[i + j]))
			break;
		j++;
	}
	return(j);
}
void	tokenization(t_data *data)
{
	int	i;
	
	i = 0;
	while(data->line_read[i])
	{
		i += is_white_space(data->line_read , i);
		if(check_token_type(data->line_read[i]))
			i+= tok_redirections(data->line_read, i, &data->struc_tok);
		else
			i+= tok_word(data->line_read, i, &data->struc_tok);			
	}
}
