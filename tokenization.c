/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:25:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/05 16:51:13 by jpelaez-         ###   ########.fr       */
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

void	tokenization(t_data *data)
{
	int	len;
	int	i;
	char	*delimiter;
	
	delimiter = "\"$\'&<>=| \f\n\r\t\v(){}/";
	len = count_tokens(data->line_read, delimiter);
	data->tokens = (char **)malloc(sizeof(char *) * (len + 1));
	if (!data->tokens)
		error_msg("allocation error");
	split_tok(data, data->line_read, delimiter);
}
