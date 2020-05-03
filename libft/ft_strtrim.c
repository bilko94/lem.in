/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:11:04 by solivari          #+#    #+#             */
/*   Updated: 2019/06/12 15:59:05 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	char	*ptr;

	if (!s)
		return (NULL);
	if ((s[0] == '\0') && (ft_strcmp(s, "") == 1))
		return (NULL);
	i = 0;
	while ((s[i] == '\t') || (s[i] == '\n') || (s[i] == ' '))
		i++;
	k = ft_strlen(s) - 1;
	while (((s[k] == '\t') || (s[k] == '\n') || (s[k] == ' ')) && (k > 0))
		k--;
	if (i > k)
		return (ft_strnew(1));
	if (!(ptr = ft_strnew(k + 1 - i)))
		return (NULL);
	return (ft_strncpy(ptr, &s[i], k + 1 - i));
}
