/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils_added.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:28:10 by rrask             #+#    #+#             */
/*   Updated: 2023/08/30 15:10:42 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	content_check(char *str)
{
	int	i;
	int	exist_val;

	i = 0;
	exist_val = 0;
	while (str[i] && (str[i] != '='))
		i++;
	if (str[i] == '=')
	{
		exist_val = 1;
		{
			if (str[i + 1] != '\0')
				exist_val = 2;
		}
	}
	return (exist_val);
}

int	is_first_alpha(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !*arg)
		return (0);
	if (!((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z')))
		return (-1);
	while ((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z'))
		i++;
	return (1);
}

void	error_msg_export(char *msg, char *input)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(input, 2);
	ft_putendl_fd(" not valid identifier", 2);
}
