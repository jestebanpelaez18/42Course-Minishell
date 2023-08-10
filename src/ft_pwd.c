/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:08:02 by junheeki          #+#    #+#             */
/*   Updated: 2023/08/10 17:55:16 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/param.h>
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}

int		ft_pwd(void)
{
	char cwd[PATH_MAX];

	if(getcwd(cwd, PATH_MAX))
	{
		ft_putendl_fd(cwd, 1);
		return(0);
	}
	else
		return(1);
}

int	main()
{
	// str = getenv(e_cpy[0]);
	ft_pwd();
	return (0);
}
