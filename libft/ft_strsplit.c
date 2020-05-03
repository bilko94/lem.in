/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:25:09 by solivari          #+#    #+#             */
/*   Updated: 2019/06/12 17:31:21 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	if (!s || !c)
		return (NULL);
	i = 0;
	j = 0;
	if (!(arr = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(*arr))))
		return (NULL);
	while (s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		arr[i] = ft_strnew(ft_wordlen(s, c));
		while (*s != c && *s != '\0')
			arr[i][j++] = *s++;
		i++;
		j = 0;
	}
	arr[i] = NULL;
	return (arr);
}
