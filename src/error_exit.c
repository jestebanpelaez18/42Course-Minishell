/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:03:02 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/10 16:15:45 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error_msg_noexit(char *msg)
{
	ft_putendl_fd(msg, 2);
}

void	free_argt(char **argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		free(argument[i]);
		argument[i] = NULL;
		i++;
	}
	free(argument);
}

void	error_msg_command(char *msg, char *command)
{
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(command, 2);
}