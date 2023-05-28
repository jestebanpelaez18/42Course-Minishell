/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:19:57 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/11/16 14:41:40 by jpelaez-         ###   ########.fr       */
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
