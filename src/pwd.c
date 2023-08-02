/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:08:02 by junheeki          #+#    #+#             */
/*   Updated: 2023/08/02 16:17:52 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/param.h>

void pwd()
{
	char cwd[MAXPATHLEN];

	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}
