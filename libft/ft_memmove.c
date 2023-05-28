/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:37:27 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/11/14 13:40:53 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*array_dst;
	unsigned char	*array_src;
	size_t			i;

	i = 0;
	array_dst = (unsigned char *)dst;
	array_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	if (dst > src)
	{
		while (len-- > 0)
		{
			array_dst[len] = array_src[len];
		}
	}
	else
	{
		while (i < len)
		{
			array_dst[i] = array_src[i];
			i++;
		}
	}
	return (dst);
}
