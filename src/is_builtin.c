/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:20 by rrask             #+#    #+#             */
/*   Updated: 2023/08/10 17:17:13 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

/*Compares if the given command is from a list of builtins or not.
Returns -1 if the str is empty or is there is no match,
otherwise 0 or higher.*/
int	is_builtin(char *str)
{
	int				i;
	int				len;
	static char		*arr[2] = {"echo", "unset"};

	if (!str)
		return (-1);
	len = ft_strlen(str);
	i = 0;

	while (arr[i] && i <= 2 && ft_strncmp(str, arr[i], len) != 0)
	{
		i++;
	}
	if (i >= 2)
		i = -1;
	return (i);
}

/*TESTING*/
// int	main(int argc, char **arg)
// {
// 	int	i;

// 	(void)argc;
// 	i = is_builtin(arg[1]);

// 	printf("%d\n", i);
// 	return (0);
// }