/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:29:03 by solivari          #+#    #+#             */
/*   Updated: 2019/06/11 14:52:08 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			*dst1;
	unsigned const char		*src1;
	unsigned char			c1;

	c1 = c;
	dst1 = dst;
	src1 = src;
	i = -1;
	while (++i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == c1)
			return (dst + i + 1);
	}
	i = n;
	return (NULL);
}
