/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:22:27 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/10 20:14:25 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	count_tokens(char *line, char *del)
// {
// 	int	i;
// 	int	j;
// 	int	len;

// 	i = 0;
// 	len = 1;
// 	while (line[i] != '\0')
// 	{
// 		j = 0;
// 		while (del[j] != '\0' && del[i] != line[j])
// 		{
// 			if (line[i] == del[j])
// 			{
// 				len++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (len);
// }

int tok_closed_quotes(char *str, int i, char quote)
{
	int j;

	j = 0;
	if(str[i+j] == quote)
	{
		j++;
		while (str[i + j] != '\0' && str[i + j] != quot)
				j++;
		j++;
	}
	return(j);
}
static int	check_delimiter(char c, char *delimiter)
{
	int j;

	j = 0;
	while (delimiter[j] != '\0')
	{
		if (delimiter[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int is_whitespace(char *line, int i)
{
	char *delimiter;
	int j;

	j = i;
	delimiter = " \f\n\r\t\v";
	while(!check_delimiter(line[j],delimiter))
		j++;
	return(j);
}

int check_token_type(char c)
{
	if(c == "|" || c == ">" || c == "<")
		return(1);
	return(0);
}