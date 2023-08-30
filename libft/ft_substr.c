/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:43:38 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/30 17:01:38 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	j;
	size_t	space;

	if (s == NULL)
		return (0);
	i = start;
	space = start;
	j = 0;
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (start >= ft_strlen(s))
	{
		*s2 = '\0';
		return (s2);
	}
	if (s2 == NULL)
		return (0);
	while (s[i] != '\0' && i < len + space)
		s2[j++] = s[i++];
	s2[j] = '\0';
	return (s2);
}
