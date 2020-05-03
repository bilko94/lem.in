/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:40:50 by solivari          #+#    #+#             */
/*   Updated: 2019/06/11 14:52:09 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;
	int		len;

	if (!s || !f)
		return (NULL);
	i = -1;
	len = ft_strlen(s);
	if (!(ptr = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	while (s[++i])
		ptr[i] = f(s[i]);
	ptr[i] = '\0';
	return (ptr);
}
