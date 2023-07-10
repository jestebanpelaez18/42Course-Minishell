/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:25:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/10 13:09:13 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*create_tok(char *line, int start, int end)
{
}

int check_token_type(char *line)
{
	
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
