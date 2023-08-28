/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:43:04 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/28 16:40:26 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exit(t_data *data)
{
	if (data->struc_cmd)
		reset_cmds(&data->struc_cmd);
	if (data->struc_tok)
		reset_token(&data->struc_tok);
	free_argt(data->env);
	free(data->line_read);
	return ;
}

int	handle_exit_s(int exit_n)
{
	if (exit_n < 0)
		exit_n = exit_n % 256;
	else if (exit_n > 0 && exit_n < 256)
		return (exit_n);
	else if (exit_n >= 256)
		exit_n = exit_n % 256;
	return (exit_n);
}

void	check_argument(t_data *data, char *str)
{
	int	exit_arg;
	int	exit_s;

	exit_arg = 0;
	exit_s = 0;
	if (!str)
		g_var.g_exit_status = 0;
	else if (is_numeric_parameters(str))
	{
		exit_arg = ft_atoi(str);
		exit_s = handle_exit_s(exit_arg);
		g_var.g_exit_status = exit_s;
	}
	else
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd("numeric argument required", 2);
		g_var.g_exit_status = 255;
	}
	free_exit(data);
	exit(g_var.g_exit_status);
}

int	ft_exit(t_data *data, char **argv)
{
	ft_putendl_fd("Exit", 2);
	if (argv[1] && argv[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (1);
	}
	check_argument(data, argv[1]);
	return (0);
}
