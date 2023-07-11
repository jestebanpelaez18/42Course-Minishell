/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizations_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:49:05 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/11 16:59:11 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_operator handle_single_op(char operator)
{
    if(operator == '>')
		return(RIGH_R);
	else if (operator == '<')
		return(LEFT_R);
	else
		return(PIPE);
	return(0);
}