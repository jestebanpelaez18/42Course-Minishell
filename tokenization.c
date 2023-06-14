/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:25:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/14 17:37:07 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_tokens(char *line, char *del)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (del[j] != '\0')
		{
			if (line[i] != del[j])
				len++;
			j++;
		}
		i++;
	}
	printf(" esto es %d\n", len);
	return (len);
}

void	create_tok(t_data *data)
{
	char	*delimiter;
	int		len;

	delimiter = " \t\n";
	len = count_tokens(data->line_read, delimiter);
	data->tokens = (char **)malloc(sizeof(char *) * (len + 1));
}
