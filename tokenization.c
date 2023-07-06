/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:25:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/06 21:25:37 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*create_tok(char *line, int start, int end)
{
}

static void	split_tok(t_data *data, char *line)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 0;
	j = 0;
	while (line[i])
	{
		start = i;
		while (!check_delimiter(line[i], " \f\n\r\t\v"))
			i++;
		end = i;
		// do more stuff
	}
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
			i+= tok_redirection();
		else
			i+= tok_word();	
	}
}
