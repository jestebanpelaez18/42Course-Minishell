/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:40:15 by nvan-den          #+#    #+#             */
/*   Updated: 2023/08/16 12:59:02 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

void	n_function(char **argv)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (!argv || (argv[i] && (strncmp(argv[i], "echo", 4) != 0)))
	{
		return ;
	}
	i++;
	while (argv[i] && (strncmp(argv[i], "-n", strlen(argv[i])) == 0))
	{
		n_flag = 1;
		i++;
	}
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1] && argv[i][0] != '\0')
			write(1, " ", 1);
		i++;
	}
	if (n_flag == 0)
		write(1, "\n", 1);
}

int	ft_echo(char **argv)
{
	int		i;

	i = 1;
	if (!argv)
		return (-1);
	if (strlen(*argv) > 1)
		n_function(argv);
	return (0);
}
