/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:19:57 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 16:59:41 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*array;

	array = s;
	while (n != 0)
	{
		if (*(unsigned char *)array == (unsigned char)c)
		{
			return ((void *)array);
		}
		array++;
		n--;
	}
	return (0);
}
