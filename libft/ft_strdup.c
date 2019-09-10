/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:21:40 by solivari          #+#    #+#             */
/*   Updated: 2019/06/11 14:52:09 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str2;
	int		i;

	i = ft_strlen(str);
	str2 = (char *)malloc(i + 1);
	if (str2 != NULL)
		return (ft_strcpy(str2, str));
	else
		return (str2);
}
