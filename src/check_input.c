/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:43:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 12:18:12 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*Check if the input is a white space*/
static int	white_space(char *input)
{
	int	i;

	i = 0;
	if (input[0] == '\0')
		return (0);
	while (input[i] != '\0')
	{
		if (input[i] != ' ' || input[i] != '\t' || input[i] != '\v'
			|| input[i] != '\f' || input[i] != '\n' || input[i] != '\r')
			return (1);
		i++;
	}
	free(input);
	return (0);
}

static int	closed_quotes(char *str)
{
	int		i;
	char	quot;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quot = str[i++];
			while (str[i] != '\0' && str[i] != quot)
				i++;
		}
		if (str[i] == '\0')
		{
			error_msg_noexit("unclosed quotes", 258);
			free(str);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	close_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '|')
	{
		error_msg_noexit("zsh: parse error near '|' ", 258);
		free(str);
		return (0);
	}
	return (1);
}

static int	correct_input(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '|')
	{
		error_msg_noexit("zsh: parse error near '|' ", 258);
		free(line);
		return (0);
	}
	while (line[i] != '\0')
	{
		i++;
		if (line[i] == '|' && line[i + 1] == '|')
		{
			error_msg_noexit("zsh: parse error near '|' ", 258);
			free(line);
			return (0);
		}
	}
	return (1);
}

int	check_line(t_data *data, char *line)
{
	char	*temp_line;

	if (!white_space(line))
		return (0);
	temp_line = ft_strtrim(line, " \t\n");
	if (!temp_line | !temp_line[0])
	{
		free(line);
		free(temp_line);
		return (0);
	}
	if (!correct_input(temp_line) || !close_pipe(temp_line))
	{
		free(data->line_read);
		return (0);
	}
	if (!closed_quotes(temp_line) || !syntax_redirection(temp_line))
	{
		free(data->line_read);
		return (0);
	}
	free(data->line_read);
	data->line_read = temp_line;
	return (1);
}
