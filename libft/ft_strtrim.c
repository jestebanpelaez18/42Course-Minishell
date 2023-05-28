/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:57:39 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/11/14 17:08:11 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(unsigned char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0' && set[i] != c)
		i++;
	if (set[i] == c)
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		start;
	int		end;

	if (s1 == NULL)
		return (0);
	s2 = 0;
	if (s1 != 0 && set != 0)
	{
		end = ft_strlen(s1);
		start = 0;
		while (s1[start] != '\0' && ft_checkset(s1[start], set) == 1)
			start++;
		while (s1[end - 1] && ft_checkset(s1[end - 1], set) == 1 && end
			- 1 > start)
			end--;
		s2 = ft_substr(s1, start, end - start);
	}
	return (s2);
}
