/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:04:23 by solivari          #+#    #+#             */
/*   Updated: 2019/06/11 14:52:08 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	k;
	int	neg;

	i = 0;
	k = 0;
	neg = 1;
	while ((str[k] == '\n' || str[k] == ' ' || str[k] == '\t' || str[k] == '\r'\
				|| str[k] == '\f' || str[k] == '\v'))
		k++;
	if (str[k] == '-' || str[k] == '+')
		if (str[k++] == '-')
			neg = -1;
	while (ft_isdigit(str[k]))
	{
		i *= 10;
		i += str[k] - 48;
		k++;
	}
	return (i * neg);
}
