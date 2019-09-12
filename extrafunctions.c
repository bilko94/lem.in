/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrafunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:43:01 by solivari          #+#    #+#             */
/*   Updated: 2019/09/12 15:26:38 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_arraylen(char **str)
{
	int	i;

	i = 0;
	while (str[i++] != '\0');
	return (i);
}

int		ft_list_size(t_room *roomlist)
{
	int	i;

	i = -1;
	while (roomlist)
	{
		i++;
		roomlist = roomlist->next;
	}
	return (i);
}

void	printstack(t_rd **rd)
{
	t_rd	*cursor;

	cursor = (*rd);
	while (cursor->next)
	{
		printf("\t\t%s\n", cursor->line);
		cursor = cursor->next;
	}
}