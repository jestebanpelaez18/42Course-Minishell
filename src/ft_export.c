/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:52 by rrask             #+#    #+#             */
/*   Updated: 2023/08/22 19:19:44 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Get environment.
2. Add variables to the end of the list.
3. If the variable exists: rewrite it with the given argument.

EDGECASE: Handle every argument after export.
*/

#include "../inc/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

static int	is_alpha(char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z'))
		return (1);
	else
		return (0);
}

//export : with no arg -> print export with "declare -x "
//

void	print_export(char **env, int fd)
{
	int	i;
	char	**e_cpy;
	char	*str;

	i = 0;
	str = getenv(e_cpy[i]);
	while (str[i])
	{
		ft_putstr_fd("declare -x ", fd);
		printf("%s", e_cpy[i]);
		// print_quote(str[i], fd);
		ft_putchar_fd('\n', fd);
		free(e_cpy[i]);
		i++;
	}
}


static char	**ft_export(char *arg, char **env)
{
	if (!arg || !*arg)
		return (NULL);
	(void)env;
	/*
		takes the argument and allocates it into the environment.
		only receives alpha, no numbers, no non-alphabetical for first letter
	*/
	if (is_alpha(arg)) //Add recognition for numbers
	{
		printf("%s is now a variable.\n", arg); //Allocate at the end of env
	}
	else
	{
		printf("export: not an identifier: %s", arg);
	}
	return (env);
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int fd;

	(void)argc;
	i = 1;
	if (!argv || (argv[i] && (strncmp(argv[i], "export", 7) != 0)))
		//CHANGE TO FT
		return (-1);
	i++;
	if (argv[i]) //If there are additional arguments after export
	{
		while (argv[i])
		{
			ft_export(argv[i], env);
			i++;
		}
	}
	else //Export only, prints environment variables
	{
		i = 0;
		while (env[i])
		{
			print_export(env, fd);
			// ft_putstr_fd("declare -x ", fd);
			// //print_quote(str[i], fd);
			// printf("%s", str[i]);
			// ft_putchar_fd('\n', fd);
			// free(str[i]);
			// i++;
			// // printf("declare -x %s\n", env[i]);
			// // i++;
		}
	}
	return (0);
}
