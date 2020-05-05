/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:18:28 by solivari          #+#    #+#             */
/*   Updated: 2019/06/11 14:52:10 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int cin)
{
	int	i;

	i = ft_strlen((char *)str);
	if ((cin == '\0') && (str[i] == '\0'))
		return ((char *)&str[i]);
	else
		while (--i != -1)
			if (str[i] == cin)
				return ((char *)&str[i]);
	return (0);
}
