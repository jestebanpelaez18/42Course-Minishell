/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:15:25 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/11/15 13:45:54 by jpelaez-         ###   ########.fr       */
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
