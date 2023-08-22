/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:52 by rrask             #+#    #+#             */
/*   Updated: 2023/08/22 18:35:56 by junheeki         ###   ########.fr       */
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

static int	is_alpha(char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z'))
		return (1);
	else
		return (0);
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

// int			ft_export(t_cmd *cmd_list, char ***envp, int fd)
// {
// 	int			i;
// 	int 		keyindex;

// 	i = 1;
// 	while(cmd_list->cmdline[i].cmd && cmd_list->cmdline[i].redir_flag == 0)
// 	{
// 		if (isvalid_export(cmd_list->cmdline[i].cmd))
// 		{
// 			if ((keyindex = check_key(*envp, cmd_list->cmdline[i].cmd)) >= 0)
// 			{
// 				if (haveequal(cmd_list->cmdline[i].cmd))
// 					add_key_envp(envp, cmd_list->cmdline[i].cmd, keyindex);
// 					//key가 있는데 value가 없이 들어오면 아무 처리 안해줌.
// 			}
// 			else
// 				add_envp(cmd_list->cmdline[i].cmd, envp);//key가 없어서 새로 추가.
// 		}
// 		else//유효한 키가 아닐때,
// 			cmd_list->err_manage.errcode = 5;
// 		i++;
// 	}
// 	if (!(cmd_list->cmdline[1].cmd) || cmd_list->cmdline[1].redir_flag == 1)
// 		print_export(*envp, fd);
// 	if (cmd_list->err_manage.errcode == 5)
// 		return (-1);
// 	return (1);
// }

int	main(int argc, char **argv, char **env)
{
	int	i;

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
			printf("declare -x %s\n", env[i]);
			i++;
		}
	}
	return (0);
}
