/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:12:57 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/11/16 14:30:02 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i < len && *big != '\0')
	{
		if (*little == *big)
		{
			j = 1;
			while (little[j] == big[j] && i + j < len && little[j] != '\0')
			{
				j++;
			}
			if (little[j] == '\0')
				return ((char *)big);
		}
		big++;
		i++;
	}
	return (0);
}
