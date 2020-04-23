/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:09:43 by solivari          #+#    #+#             */
/*   Updated: 2019/06/11 14:52:09 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	dstlen = 0;
	while (dst[dstlen] != '\0' && dstlen < dstsize)
		dstlen++;
	i = dstlen;
	while ((src[dstlen - i] != '\0') && (dstlen + 1 < dstsize))
	{
		dst[dstlen] = src[dstlen - i];
		dstlen++;
	}
	if (i < dstsize)
		dst[dstlen] = '\0';
	return (i + ft_strlen(src));
}
