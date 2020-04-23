/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:57:27 by solivari          #+#    #+#             */
/*   Updated: 2019/06/11 14:52:08 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	str = (char *)malloc(size * sizeof(char));
	if (str != NULL)
		return (ft_memset(str, 0, size * sizeof(char)));
	else
		return (NULL);
}
