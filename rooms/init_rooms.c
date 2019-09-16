/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:33:31 by solivari          #+#    #+#             */
/*   Updated: 2019/09/16 17:23:27 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*createhead(t_room **roomlist)
{
	(*roomlist) = init_room();
	return (*roomlist);
}

t_room	*init_room(void)
{
	t_room	*room;
	
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	room->name = NULL;
	room->start = 0;
	room->end = 0;
	room->x = 0;
	room->y = 0;
	room->link_count = 0;
	room->occupied = false;
	room->links = NULL;
	room->next = NULL;
	return (room);
}

t_room	*set_room(char *str)
{
	char	**str1;
	t_room	*room;

	str1 = ft_strsplit(str, ' ');
	room = init_room();
	room->name = str1[0];
	room->x = ft_atoi(str1[1]);
	room->y = ft_atoi(str1[2]);
	return (room);
}
