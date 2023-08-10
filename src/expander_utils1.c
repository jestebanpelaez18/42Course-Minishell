/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:59:25 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/03 18:33:55 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_number(char argument)
{
	if (argument >= '0' && argument <= '9')
		return (1);
	return (0);
}

int	skip_digit(int i, char *str)
{
	int	j;

	j = i;
	while (str[j] != '\0' && is_number(str[j]))
		j++;
	return (j - i);
}

int	is_dollar(char *tok)
{
	int	i;

	i = 0;
	while (tok[i] != '\0')
	{
		if (tok[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	is_equal(char *env)
{
	int	i;

	i = 0;
	while (env[i] != '\0' && env[i] != '=')
		i++;
	return (i);
}

int	len_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	return (i);
}
