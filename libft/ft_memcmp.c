/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:42:20 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 16:59:45 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const char	*array1;
	const char	*array2;

	array1 = str1;
	array2 = str2;
	while (n != 0)
	{
		if (*(unsigned char *)array1 != *(unsigned char *)array2)
			return (*(unsigned char *)array1 - *(unsigned char *)array2);
		array1++;
		array2++;
		n--;
	}
	return (0);
}
