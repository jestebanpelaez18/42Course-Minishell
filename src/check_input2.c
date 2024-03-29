/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:20:07 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 12:05:17 by jpelaez-         ###   ########.fr       */
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
		error_msg_noexit("zsh: parse error near '\\n'", 258);
		return (0);
	}
	if ((line[i - 1] == '>' && line[i - 2] == '>') || (line[i - 1] == '<'
			&& line[i - 2] == '<'))
	{
		error_msg_noexit("zsh: parse error near '\\n'", 258);
		return (0);
	}
	return (1);
}

int	syntax_redirection(char *line)
{
	if (!unclosed_redirec(line))
	{
		free(line);
		return (0);
	}
	return (1);
}

void	free_line_input(char *line, char *temp_l)
{
	free(line);
	free(temp_l);
}
