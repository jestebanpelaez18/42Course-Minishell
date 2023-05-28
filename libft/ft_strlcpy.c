/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:07:45 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/11/14 13:44:49 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*source;
	size_t		source_len;
	size_t		i;

	source = src;
	source_len = ft_strlen(source);
	i = 0;
	if (dstsize == 0)
		return (source_len);
	while (src[i] != '\0' && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	else
		dst[i - 1] = '\0';
	return (source_len);
}
