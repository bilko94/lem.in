/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:53:59 by solivari          #+#    #+#             */
/*   Updated: 2019/08/12 17:05:00 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	long	i;
	int	    k;
	int	    neg;

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
