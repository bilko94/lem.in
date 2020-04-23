/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_counts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:36:31 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 18:02:20 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

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
