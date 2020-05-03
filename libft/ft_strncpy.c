/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:24:05 by solivari          #+#    #+#             */
/*   Updated: 2019/06/12 15:11:04 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int		i;
	int		k;

	i = -1;
	k = ft_strlen(src);
	while (++i < (int)n)
		if (i < k)
			dest[i] = src[i];
		else
			dest[i] = '\0';
	return (dest);
}
