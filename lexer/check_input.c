/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:43:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/11 13:51:31 by jpelaez-         ###   ########.fr       */
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
			quot = str[i];
			while (!str[i] && str[i] != quot)
				i++;
		}
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

static int	close_pipe(char *str)
{
	int	i;

	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '|')
		return (0);
	return (1);
}
int	check_line(t_data *data)
{
	char *temp_line;

	if (!white_space(data->line_read))
		return (0);
	temp_line = ft_strtrim(data->line_read, " \t\n");
	if (!temp_line)
		return (0);
	if (!closed_quotes(temp_line))
		return (0);
	if (!close_pipe(temp_line))
		return (0);
	return (1);
}
