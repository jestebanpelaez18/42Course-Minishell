/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:42:20 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/11/14 13:55:22 by jpelaez-         ###   ########.fr       */
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
