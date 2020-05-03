/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:26:04 by solivari          #+#    #+#             */
/*   Updated: 2019/06/12 12:32:35 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *ned)
{
	char	bf2;
	int		i;
	int		j;
	int		k;

	k = ft_strlen(hay) - ft_strlen(ned);
	i = -1;
	if (ft_strncmp(ned, "", 1) == 0)
		return ((char *)hay);
	while (++i <= k)
		if (hay[i] == ned[0])
		{
			j = 0;
			bf2 = 1;
			while (((size_t)++j != ft_strlen(ned)) && (bf2 != 0))
				if (hay[i + j] != ned[j])
					bf2 = 0;
			if (bf2 == 1)
				return ((char *)&hay[i]);
		}
	return (NULL);
}
