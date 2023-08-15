/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:40:15 by nvan-den          #+#    #+#             */
/*   Updated: 2023/08/15 14:06:09 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	n_function(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] && ft_strncmp(argv[i], "-n", 4) == 0)
		i++;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1] && argv[i][0] != '\0')
			write(1, " ", 1);
		i++;
	}
}

int	ft_echo(char **argv)
{
	int		i;

	i = 1;
	if (ft_strlen(*argv) > 1)// check "-n" new line option in echo
		n_function(argv);
	else
		write(1, "\n", 1);
	return (0);
}
