/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:08:02 by junheeki          #+#    #+#             */
/*   Updated: 2023/08/09 18:01:17 by junheeki         ###   ########.fr       */
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

int		ft_pwd(char **args)
{
	char *dir;
	char *buf[PATH_MAX];

	(void)args;
	dir = getcwd(buf, PATH_MAX);
	if (dir == NULL)
		return (1);
	ft_putendl_fd(dir, 1);
	free(dir);
	return (0);
}

int	main(int argc, char **arg, char **env)
{
	char	**e_cpy;
	char	*str;
	// int	pwd;
	(void)argc;
	(void)arg;

	e_cpy = env;

	// str = getenv(e_cpy[0]);
	ft_pwd(e_cpy);
	return (0);
}
