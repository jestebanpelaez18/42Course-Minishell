/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:52:33 by rrask             #+#    #+#             */
/*   Updated: 2023/08/08 16:41:38 by rrask            ###   ########.fr       */
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
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
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

int	get_env_var(char *arg, char **env)
{
	int	i;

	if (!arg || !env)
		return (-1);
	i = 0;
	while (ft_strncmp(arg, *env, 3))
	{
		// Need to check the EXACT string before '='
		// in cases where the word appears at other places, like TERM/TERM_SESSION_CLASS
		i++;
		env++;
	}
	return (i);
}

int	main(int argc, char **arg, char **env)
{
	char	**e_cpy;
	char	*str;
	int		index;

	(void)argc;
	e_cpy = env;
	index = get_env_var(arg[1], e_cpy);
	printf("Match at: %d\n", index);
	str = getenv(e_cpy[index]);
	printf("%s\n", str);
	// print_env(e_cpy);
	return (0);
}
