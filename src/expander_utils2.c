/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:25:49 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/31 15:44:42 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dolar_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			break ;
		i++;
	}
	return (i);
}

int	no_single_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			return (0);
		else if (str[i] == '\"')
			return (1);
		i++;
	}
	return (1);
}

char	*get_str(char *str, char c)
{
	char	*s2;
	size_t	i;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (s2 == NULL)
		return (0);
	i = 0;
	if (!str)
	{
		s2[i] = c;
		s2[i + 1] = 0;
	}
	else
	{
		while (str[i])
		{
			s2[i] = str[i];
			i++;
		}
		s2[i] = c;
		s2[i + 1] = 0;
		free(str);
	}
	return (s2);
}

int	dollar_tok_len(char *str, int j)
{
	int	i;
	int	k;

	i = j;
	k = 0;
	while (str[i] && str[i] != '\"' && str[i] != '\'' && str[i] != ' '
		&& str[i] != '$' && str[i] != '\\' && str[i] != '=' && str[i] != ':'
		&& str[i] != '/' && str[i] != '-')
	{
		k++;
		i++;
	}
	return (k);
}

char	*rm_double_quotes(char *str)
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
		if (str[i] != '\"')
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
