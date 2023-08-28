/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:34:05 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/27 13:28:38 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_number(char argument)
{
	if (argument >= '0' && argument <= '9')
		return (1);
	return (0);
}

int	is_numeric_parameters(char *param)
{
	int	i;

	i = 0;
	if ((param[i] == '-' || param[i] == '+') && param[i + 1] != '\0')
		i++;
	while (param[i] != '\0')
	{
		if (!is_number(param[i]))
			return (0);
		i++;
	}
	return (1);
}