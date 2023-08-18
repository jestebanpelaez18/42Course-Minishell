/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:47:41 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/17 15:04:17 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rm_single_quotes(char *str)
{
	int		i;
	int		j;
	char	*temp;

	temp = ft_strdup("");
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\'')
		{
			temp[j] = str[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	free(str);
	return (temp);
}

void	remove_quotes(t_token *current)
{
	char	*str;

	if (no_single_quotes(current->tokens))
	{
		str = rm_double_quotes(current->tokens);
		str = rm_single_quotes(str);
		current->tokens = str;
	}
	else
	{
		str = rm_single_quotes(current->tokens);
		current->tokens = str;
	}
}
