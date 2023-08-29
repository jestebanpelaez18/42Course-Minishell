/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:05:44 by rrask             #+#    #+#             */
/*   Updated: 2023/08/29 14:44:10 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	istheres(char *joined, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		joined[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined[j] = s2[i];
		i++;
		j++;
	}
	joined[j] = '\0';
}

char	*ft_strjoinfree(char const *buf, char const *read_buf)
{
	char	*joined;
	int		buf_len;
	int		read_buf_len;

	if (!buf)
		buf_len = 0;
	else
		buf_len = ft_strlen(buf);
	read_buf_len = ft_strlen(read_buf);
	joined = ft_calloc(buf_len + read_buf_len + 1, sizeof(char));
	if (!joined)
		return (NULL);
	istheres(joined, buf, read_buf);
	if (buf)
		free((void *)buf);
	return (joined);
}
