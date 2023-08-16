/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:40:15 by nvan-den          #+#    #+#             */
/*   Updated: 2023/08/16 13:10:40 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	n_function(char **argv)
{
	int	i;
	int	n_flag;

	i = 0;
	n_flag = 0;
	if (!argv || (argv[i] && (ft_strncmp(argv[i], "echo", 4) != 0)))
	{
		return ;
	}
	i++;
	while (argv[i] && (ft_strncmp(argv[i], "-n", ft_strlen(argv[i])) == 0))
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

	i = 0;
	if (!argv)
		return (-1);
	if (ft_strlen(*argv) > 1)
		n_function(argv);
	return (0);
}
