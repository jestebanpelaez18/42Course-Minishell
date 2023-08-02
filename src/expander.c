/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:16:46 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/02 17:33:24 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	**check_expander(t_data *data, char **commands)
// {
// 	int	i;

// 	i = 0;
// 	while (commands[i])
// 	{
//         if(commands[i])
// 	}
// }

// t_cmd	*expander(t_data *data, t_cmd *cmds)
// {
// 	cmds->commands = check_expander(data, cmds->commands);

// 	return (cmds);
// }

int	expand_env(char **temp, int i, t_data *data, char *str)
{
	char	**envp;
	int		j;
	int		n;
	int		step;

	envp = data->env;
	j = 0;
	step = 0;
	while (envp[j])
	{
		n = is_equal(envp[j]);
		if (ft_strncmp(str + i, envp[j], n) == 0
			&& (len_equal(envp[j]) == (int)ft_strlen(str + 1)))
		{
			*temp = ft_strjoin(*temp, envp[j] + len_equal(envp[j]) + 1);
			step += is_equal(envp[j]);
		}
		j++;
	}
	return (step);
}

char	*replace_dollar(char *str, t_data *data)
{
	char	*temp;
	int		i;

	temp = ft_strdup("");
	i = 0;
	while (str[i])
	{
		i += skip_digit(i, str);
		// if (str[i] == '$' && str[i + 1] == '?')
		// 	get_exit_status(temp);
		if (str[i] == '$' && (str[i + 1] != ' ' && (str[i + 2] != '"' || str[i
					+ 2] != '\0')) && str[i + 1] != '\0')
			i += expand_env(&temp, i + 1, data, str);
		else
		{
			if (str[i])
				i++;
			temp = ft_strjoin(temp, str + i);
			i++;
		}
	}
	return (temp);
}

void	expand_dollar(t_token *current, t_data *data)
{
	char	*str;

	str = replace_dollar(current->tokens, data);
	current->tokens = str;
	return ;
}

void	expander(t_data *data, t_token **token)
{
	t_token	*tok;

	tok = *token;
	while (tok)
	{
		if (is_dollar(tok->tokens))
			expand_dollar(tok, data);
		tok = tok->next;
	}
	return ;
}
