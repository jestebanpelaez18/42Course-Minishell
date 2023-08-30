/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:40:52 by rrask             #+#    #+#             */
/*   Updated: 2023/08/30 15:44:07 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_keylen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '=')
		i++;
	return (i);
}

static void	print_export_env(char **env)
{
	int			i;
	char		*key;
	char		*str;

	i = 0;
	while (env[i])
	{
		key = get_key(env[i]);
		str = get_string(env[i]);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(key, 1);
		ft_putstr_fd("\"", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\"", 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
/**/

char	**modify_env_var(t_data *data, char *arg, int len)
{
	const int	pos = match_env_key(arg, data, 0, len);
	const int	num = content_check(arg);
	const char	*key = get_key(arg);
	const char	*str = get_string(arg);

	if (num == 1)
		data->env[pos] = ft_strdup(arg);
	else if (num == 2)
		data->env[pos] = combine_str(str, key);
	free((char *)key);
	free((char *)str);
	return (data->env);
}

char	**handle_args(char *arg, t_data *data)
{
	int		index;
	int		len;
	int		key_flag;
	char	*temp;

	if (!arg || !data->env)
		return (NULL);
	index = 0;
	key_flag = 0;
	len = ft_keylen(arg);
	temp = ft_strdup(arg);
	if (is_first_alpha(arg) == 1)
	{
		if (content_check(arg) == 0)
			return (data->env);
		data->env = modify_env_var(data, temp, len);
	}
	free(temp);
	return (data->env);
}

int	ft_export(char **arg, t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!arg || (arg[i] && (ft_strncmp(arg[i], "export", 7) != 0)))
		return (1);
	i++;
	if (arg[i])
	{
		while (arg[i])
		{
			if (is_first_alpha(arg[i]) == -1)
			{
				error_msg_export("minishell: export: ", arg[i]);
				return (1);
			}
			data->env = handle_args(arg[i], data);
			i++;
		}
	}
	else
		print_export_env(data->env);
	return (0);
}
