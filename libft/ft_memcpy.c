/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:16:18 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/11/14 15:35:52 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*array_dst;
	const char	*array_src;
	size_t		i;

	i = 0;
	array_dst = dst;
	array_src = src;
	if (n == 0 || array_dst == array_src)
		return ((char *)array_dst);
	if (array_dst == NULL && array_src == NULL)
		return (NULL);
	while (i < n)
	{
		array_dst[i] = array_src[i];
		i++;
	}
	return ((char *)array_dst);
}
