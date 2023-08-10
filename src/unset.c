/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:52:33 by rrask             #+#    #+#             */
/*   Updated: 2023/08/10 16:05:07 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (str1[i] != '\0' && str2[i] != '\0')
		&& str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

static int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;

	while (str[i])
		i++;
	return (i);
}

// void	print_env(char **env)
// {
// 	if (!env)
// 		return ;
// 	while (*env)
// 	{
// 		printf("%s\n", *env);
// 		env++;
// 	}
// }

int	get_env_var(char *arg, char **env, int index, int len)
{
	int	i;

	if (!arg || !*env)
		return (-1);
	i = index;
	while (env[i] && ft_strncmp(arg, env[i], len))
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **arg, char **env)
{
	char	**e_cpy;
	char	*str;
	int		index;
	int		len;

	if (argc != 2)
		return (0);
	if (!arg[1])
		return (0);
	index = 0;
	e_cpy = env; //MALLOC NEW 2D ARRAY
	len = ft_strlen(arg[1]);
	index = get_env_var(arg[1], e_cpy, index, len);
	while (e_cpy[index] && e_cpy[index][len] != '=')
	{
		// printf("Match at: %d\n", index);
		index = get_env_var(arg[1], e_cpy, index + 1, len);
	}
	// print_env(e_cpy);
	str = getenv(e_cpy[index]);
	printf("%s\n", str);
	return (0);
}
