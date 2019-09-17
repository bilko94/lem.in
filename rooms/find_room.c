/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:38:20 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 16:38:27 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*find_room(t_hub **hub, char *str)
{
	t_room	*cursor;
	
	cursor = (*hub);
	while (cursor->next)
	{
		if (ft_strcmp(cursor->name, str) == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}
