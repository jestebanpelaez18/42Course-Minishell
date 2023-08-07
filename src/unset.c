/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:26:05 by rrask             #+#    #+#             */
/*   Updated: 2023/08/07 13:04:23 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/wait.h>

//I need to compare for the exact location within the env string and modify that variable
int main(int argc, char **arg, char **env)
{
	(void)argc;
	(void)arg;

	while(*env)
	{
		printf("%s\n", *env);
		env++;
	}

	return 0;
}