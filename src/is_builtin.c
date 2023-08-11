/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:20 by rrask             #+#    #+#             */
/*   Updated: 2023/08/11 13:38:27 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	if (!str1 || !str2)
		return (0);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 != len2)
		return (0);
	while (i < len2 && (str1[i] != '\0' && str2[i] != '\0')
		&& str1[i] == str2[i])
	{
		i++;
	}
	if (i == len2)
		return (1);
	return (0);
}

/*Compares if the given command is from a list of builtins or not.
Returns -1 if the str is empty, 0 if no match and 1 if there is a match.*/
int	is_builtin(char *str)
{
	int				i;
	int				flag;
	static char		*arr[3] = {"echo", "unset", "export"};

	if (!str)
		return (-1);
	i = 0;
	flag = 0;
	while (arr[i] && i <= 2)
	{
		if (ft_strcmp(str, arr[i]) == 1)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

/*TESTING*/
int	main(int argc, char **arg)
{
	int	i;

	(void)argc;
	// (void)arg;
	i = is_builtin(arg[1]);
	printf("%d\n", i);
	return (0);
}