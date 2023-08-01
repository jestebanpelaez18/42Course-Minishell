/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:16:46 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/01 19:43:50 by jpelaez-         ###   ########.fr       */
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
int	expand_envp(char *temp, int i, t_data *data)
{
	char	**envp;
	int		j;
	int		n;

	envp = data->env;
	j = 0;
	while (envp[j])
	{
		n = is_equal(envp[j]);
		if (ft_strncmp(temp + i, envp[j], n) == 0)
		{
			
			
		}
		j++;
	}
}

char	*replace_dollar(char *str, t_data *data)
{
	char	*temp;
	int		i;

	temp = ft_strdup("");
	while (str[i])
	{
		i += skip_digit(i, str);
		if (str[i] == '$' && str[i + 1] == '?')
			get_exit_status(temp);
		else if (str[i] == '$' && (str[i + 1] != ' ' && (str[i + 2] != '"'
						|| str[i + 2] != '\0')) && str[i + 1] != '\0')
			i += expand_env(&temp, i + 1, data);
		else
		{
		}
	}
	return (temp);
}

void	expand_dollar(t_token *current, t_data *data)
{
	char	*str;

	str = replace_dollar(current->tokens, data);
	current->tokens = str;
	return (1);
}

t_token	*expander(t_data *data, t_token *token)
{
	t_token *tok;

	tok = token;
	while (tok)
	{
		if (is_dollar(token->tokens))
			expand_dollar(tok, data);
		tok = tok->next;
	}
}