/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:47:41 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/04 18:57:51 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rm_single_quotes(char *str)
{
	int i;
	int j;
	char *temp;

	temp = ft_strdup("");
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\'')
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