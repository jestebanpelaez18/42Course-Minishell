/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:41:12 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/01 19:36:33 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void init_data(t_data *data, char **env)
{
    data->env = envdup(env);
    data->exit_status = 0;
}
int main(int argc, char **argv, char **env)
{
    t_data data;
    (void)argv;
    if(argc > 1)
        error_msg("No arguments for minishell");
    // if(!env || (*env))
    //     error_msg("No enviroment");
    // for (char **envp = env; *envp != 0; envp++)
    // {
    //     char *thisEnv = *envp;
    //     printf("%s\n", thisEnv);    
    // }
    init_data(&data, env);
    while(42)
    {
        start_signal();
    }
    return(0);
}