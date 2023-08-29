/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:47:41 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/29 16:50:10 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rm_single_quotes(char *str)
{
	int		i;
	int		j;
	char	*temp;

	temp = (char *)malloc(ft_strlen(str) + 1);
	if (!temp)
		error_msg("Allocation error");
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

	if (current->prev)
		if (export_quotes(current->prev->tokens, current->tokens) == 0)
			return ;
	if (no_single_quotes(current->tokens))
	{
		if (current->tokens[0] == '\"' && current->tokens[1] == '\'')
		{
			str = rm_double_quotes(current->tokens);
			current->tokens = str;
		}
		else
		{
			str = rm_double_quotes(current->tokens);
			str = rm_single_quotes(str);
			current->tokens = str;
		}
	}
	else
	{
		str = rm_single_quotes(current->tokens);
		current->tokens = str;
	}
}

int	export_quotes(char *current, char *next)
{
	if (!current | !next)
		return (1);
	if (ft_strncmp(current, "export", ft_strlen(current) - 1) == 0)
	{
		if (ft_strncmp(next, "\"\"", 2) == 0)
			return (0);
		else if (ft_strncmp(next, "''", 2) == 0)
			return (0);
	}
	return (1);
}
