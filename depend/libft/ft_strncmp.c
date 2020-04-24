/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:19:25 by solivari          #+#    #+#             */
/*   Updated: 2019/06/12 14:06:41 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = -1;
	while (((++i < n) && ((s1[i] != '\0') || (s2[i] != '\0'))))
	{
		if (((unsigned char)s1[i] < (unsigned char)s2[i]))
			return (-1);
		if (((unsigned char)s1[i] > (unsigned char)s2[i]))
			return (1);
	}
	return (0);
}
