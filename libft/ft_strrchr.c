/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:00:59 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 17:01:27 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)s + len);
		len--;
	}
	return (0);
}
