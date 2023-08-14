/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:49:50 by junheeki          #+#    #+#             */
/*   Updated: 2023/08/10 18:05:51 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// with cd functiton, when you change your current dir, you should change
// pwd and oldpwd as well/.

// cd or cd ~ -> $HOME
// cd - -> check $OLDPWD
// if there is two arguments, go to first path
// When you move dir with CD, if there is no OLDPWD then create it.
// cd filename -> ex) cd: not a directory: echo.c
// cd wrongname -> ex) cd: no such file or directory: ech

int go_to_path(int case, t_data *data)
{

}

int ft_cd(char **args, t_data *data)
{
	int cd_ret;

	if(!argv[1])


}
