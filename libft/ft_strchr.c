/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:18:23 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 17:00:24 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*array;

	array = (char *)str;
	while (*array != (unsigned char)c && *array != '\0')
	{
		array++;
	}
	if (*array == (unsigned char)c)
		return (array);
	else
		return (0);
}
