/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:20:07 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/21 17:01:15 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	unclosed_redirec(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	if (line[i - 1] == '>' || line[i - 1] == '<')
	{
		error_msg_noexit("zsh: parse error near '\n'");
		return (0);
	}
	if ((line[i - 1] == '>' && line[i - 2] == '>') || (line[i - 1] == '<'
			&& line[i - 2] == '<'))
	{
		error_msg_noexit("zsh: parse error near '\'n''");
		return (0);
	}
	return (1);
}

int	syntax_redirection(char *line)
{
	if (!unclosed_redirec(line))
		return (0);
	return (1);
}
