/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxminrange.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:05:09 by solivari          #+#    #+#             */
/*   Updated: 2019/06/11 14:55:38 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_maxminrange(int min, int max)
{
	if (min < 0 && max < 0)
		return ((min * -1) + max);
	else if (min < 0 && max >= 0)
		return (max + (min * -1) + 1);
	else
		return (max - min);
}
