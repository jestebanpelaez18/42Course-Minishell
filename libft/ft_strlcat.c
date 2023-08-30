/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:15:25 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 17:00:51 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	k;

	if (dstsize == 0)
		return (ft_strlen(src));
	k = ft_strlen(dst);
	srclen = 0;
	if (dstsize <= k)
		return (ft_strlen(src) + dstsize);
	while (k + 1 < dstsize && src[srclen] != '\0')
	{
		dst[k++] = src[srclen++];
	}
	dst[k] = '\0';
	return (ft_strlen(dst) + (ft_strlen(src) - srclen));
}
