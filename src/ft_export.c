/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:40:52 by rrask             #+#    #+#             */
/*   Updated: 2023/08/25 18:56:13 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*	return 0 -> No Equal, No Value  ex) export USER
	return 1 -> Have Equal, No value	ex) export USER=
	return 2 -> Have Equal, with Value ex) export USER=JUN
*/
static	int	content_check(char *str)
{									
	int	i;							
	int	exist_val;

	i = 0;
	exist_val = 0;
	while (str[i] && (str[i] != '='))
		i++;
	if (str[i] == '=')
	{
		exist_val = 1;
		{
			if (str[i + 1] != '\0')
				exist_val = 2;
		}
	}
	return (exist_val);
}

static	int	is_first_alpha(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !*arg)
		return (0);
	if (!((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z')))
		return (-1);
	while ((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z'))
		i++;
	return (1);
}

static	int	ft_keylen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '=')
		i++;
	return (i);
}

static	int	match_env_key(char *arg, char **env, int index, int len)
{
	int	i;

	if (!arg || !*env)
		return (-1);
	i = index;
	while ((env[i]) && ft_strncmp(arg, env[i], len) != 0)
		i++;
	if (env[i] == '\0')
		return (-1);
	return (i);
}

static char	*get_string(char *arg)
{
	char	*str;
	int		start;
	int		end;
	int		len;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	if (!arg)
		return (NULL);
	while (arg[start] && arg[start] != '=')
		start++;
	start++;
	while (arg[end])
		end++;
	len = end - start;
	str = malloc(sizeof(char) * len + 1);
	while (start < end)
	{
		str[i] = arg[start];
		i++;
		start++;
	}
	return (str);
}

static char	*get_key(char *arg)
{
	char	*str;
	int		end;
	int		i;

	end = 0;
	i = 0;
	while (arg[end] && arg[end] != '=')
		end++;
	end++;
	str = malloc(sizeof(char) * end + 1);
	while (i < end)
	{
		str[i] = arg[i];
		i++;
	}
	return (str);
}

static	char* combine_str(const char *str, const char *key)
{
	const int		len1 = ft_strlen(key);
	const int		len2 = ft_strlen(str);
	const int		final_size = len1 + len2 + 3;
	char *const		new = ft_calloc(sizeof(char), final_size);

	ft_strlcat(new, key, final_size);
	ft_strlcat(new, "\"", final_size);
	ft_strlcat(new, str, final_size);
	ft_strlcat(new, "\"", final_size);
	return (new);
}

static	char	**modify_env_var(char **env, char *arg, int len)
{
	const int	pos = match_env_key(arg, env, 0, len);
	const int	num = content_check(arg);
	const char	*key = get_key(arg);
	const char	*str = get_string(arg);

	if (num == 1)
	{
		env[pos] = strdup(arg);
		env[pos] = ft_strjoinfree(env[pos], "\"\"");
	}
	else if (num == 2)
		env[pos] = combine_str(str, key);
	return (env);
}

char **handle_args(char *arg, char **env)
{
	int	index;
	int	len;
	int	key_flag;

	if (!arg || !env)
		return (NULL);

	index = 0;
	key_flag = 0;
	len = ft_keylen(arg);

	if (is_first_alpha(arg) == 1)
	{
		if (content_check(arg) == 0)
			return (env);
		env = modify_env_var(env, arg, len);
	}
	return (env);
}

void	ft_export(char **arg, char **env)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	if (!arg || (arg[i] && (ft_strncmp(arg[i], "export", 7) != 0)))
		return ;
	i++;
	if (arg[i])
	{
		while (arg[i])
		{
			env = handle_args(arg[i], env);
			i++;
		}
	}
	// else
	// {
	// 	i = 0;
	// 	while (env[i])
	// 		print_export_env(env);
	// }
}
