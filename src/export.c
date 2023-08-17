/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:52 by rrask             #+#    #+#             */
/*   Updated: 2023/08/16 15:52:29 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Get environment.
2. Add variables to the end of the list.
3. If the variable exists: rewrite it with the given argument.

EDGECASE: Handle every argument after export.
*/

#include <stdio.h>
#include <string.h>

static	int	is_alpha(char *arg)
{
	int	i;

	i = 0;
	while ((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z'))
		i++;
	if (arg[i])
		return (0);
	return (1);
}

void	ft_export(char *arg, char **env)
{
	if (!arg || !*arg)
		return ;
	(void)env;
	/*
		takes the argument and allocates it into the environment.
		only receives alpha, no numbers, no non-alphabetical
		
	*/
	if (is_alpha(arg))
		printf("%s is now a variable.\n", arg);
}

int	main(int argc, char **argv, char **env)
{
	int	i;

	(void)argc;
	i = 1;
	if (!argv || (argv[i] && (strncmp(argv[i], "export", 7) != 0))) //CHANGE TO FT
		return (-1);
	i++;
	if (argv[i])
	{
		while (argv[i])
		{
			ft_export(argv[i], env);
			i++;
		}
	}
	else
	{
		i = 0;
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	return (0);
}