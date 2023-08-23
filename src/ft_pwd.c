/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:08:02 by junheeki          #+#    #+#             */
/*   Updated: 2023/08/23 11:45:12 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/param.h>
#include <stdlib.h>

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