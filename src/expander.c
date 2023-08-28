/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:16:46 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/26 15:38:50 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_exit_status(char **str)
{
	char	*temp;
	int		step;

	step = 0;
	temp = ft_itoa(g_var.g_exit_status);
	*str = ft_strjoin(*str, temp);
	step = ft_strlen(temp);
	free(temp);
	return (step + 1);
}

int	expand_env(char **temp, int i, t_data *data, char *str)
{
	char	**envp;
	int		j;
	int		n;
	int		step;

	envp = data->env;
	j = 0;
	step = 1;
	while (envp[j])
	{
		n = is_equal(envp[j]);
		if (ft_strncmp(str + i, envp[j], n) == 0
			&& (len_equal(envp[j]) == dollar_tok_len(str, i)))
		{
			*temp = ft_strjoin(*temp, envp[j] + len_equal(envp[j]) + 1);
			step += is_equal(envp[j]);
		}
		j++;
	}
	if (step == 1)
		step += dollar_tok_len(str, i);
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
		// i += skip_digit(i, str);
		if (str[i] == '$' && str[i + 1] == '?')
			i += get_exit_status(&temp);
		else if (str[i] == '$' && (str[i + 1] != ' ' && (str[i + 2] != '"'
						|| str[i + 2] != '\0')) && str[i + 1] != '\0')
		{
			i += expand_env(&temp, i + 1, data, str);
		}
		else
		{
			temp = get_str(temp, str[i]);
			i++;
		}
	}
	return (temp);
}

void	expand_dollar(t_token *current, t_data *data)
{
	char	*str;
	int		j;

	j = dolar_index(current->tokens);
	if (no_single_quotes(current->tokens))
	{
		str = replace_dollar(current->tokens, data);
		str = rm_double_quotes(str);
		current->tokens = str;
	}
	else
	{
		if (current->tokens[0] != '\'' && (current->tokens[j - 1] != '\''
			&& current->tokens[j + 1] != '\0'))
		{
			str = replace_dollar(current->tokens, data);
			current->tokens = str;
		}
		else
		{
			str = rm_single_quotes(current->tokens);
			current->tokens = str;
		}
	}
}

void	expander(t_data *data, t_token **token)
{
	t_token	*tok;

	tok = *token;
	while (tok)
	{
		if (tok && tok->type == WORD && is_dollar(tok->tokens))
			expand_dollar(tok, data);
		else if (tok && tok->type == WORD)
			remove_quotes(tok);
		tok = tok->next;
	}
	return ;
}
