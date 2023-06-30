/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:25:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/30 12:47:20 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void split_tok(t_data *data, char *line, char *delimiter)
{
	int i;
	char *temp_line;

	i = 0;
	while(line[i])
	{
		while(!check_delimiter(line[i], delimiter))
			i++;
		// do more stuff
		
	}
}
void	tokenization(t_data *data)
{
	char	*delimiter;
	int		len;
	int		i;

	delimiter = " \f\n\r\t\v";
	len = count_tokens(data->line_read, delimiter);
	data->tokens = (char **)malloc(sizeof(char *) * (len + 1));
	if(!data->tokens)
		error_msg("allocation error");
	split_tok(data, data->line_read, delimiter);
}
