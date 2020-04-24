/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:28:42 by solivari          #+#    #+#             */
/*   Updated: 2019/06/11 14:52:08 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int in)
{
	char	str[10];
	char	*s;
	int		k;
	int		j;

	k = 0;
	while (!((in > -10) && (in < 10)))
	{
		str[k++] = ft_abs(in % 10) + 48;
		in /= 10;
	}
	str[k] = ft_abs(in) + 48;
	j = in > -1 ? 0 : 1;
	if (!(s = ft_strnew(k + j + 1)))
		return (NULL);
	if (j == 1)
		s[0] = '-';
	while (k > -1)
		s[j++] = str[k--];
	s[j] = '\0';
	return (s);
}
