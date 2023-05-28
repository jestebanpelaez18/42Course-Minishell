/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:32:02 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/03/22 20:47:39 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *number)
{
	int			i;
	int			sing;
	int long	result;

	i = 0;
	sing = 1;
	result = 0;
	while ((number[i] >= 9 && number[i] <= 13) || number[i] == 32)
		i++;
	if (number[i] == '+' || number[i] == '-')
	{
		if (number[i] == '-')
			sing = -1;
		i++;
	}
	while (number[i] >= '0' && number[i] <= '9')
	{
		result = result * 10 + (number[i] - '0');
		if (result > 2147483648 && sing == -1)
			return (-2);
		else if (result > 2147483647 && sing == 1)
			return (-1);
		i++;
	}
	return ((int)(result * sing));
}
