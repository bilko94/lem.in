/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:53:53 by solivari          #+#    #+#             */
/*   Updated: 2019/09/11 18:51:21 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	createroom(char **str)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	room->name = str[0];
	room->x = ft_atoi(str[1]);
	room->y = ft_atoi(str[2]);
	room->links = 0;
	room->connected = NULL;
	room->next = NULL;
}

t_room	*initializeroom(void)
{
	t_room	*room;
	
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	room->name = NULL;
	room->start = 0;
	room->end = 0;
	room->x = 0;
	room->y = 0;
	room->links = 0;
	room->connected = NULL;
	room->next = NULL;
	room->prev = NULL;
	return (room);
}

t_room	*startroom(char *str)
{
	char	**str1;
	t_room	*room;

	str1 = ft_strsplit(str, " ");
	room = initializeroom();
	room->name = str1[0];
	room->x = ft_atoi(str1[1]);
	room->y = ft_atoi(str1[2]);
	room->start = 1;
	return (room);
}

void	addstartroom(t_room **roomlist, char *line)
{
	t_room	*node;
	t_room	*cursor;

	cursor = (*roomlist);
	node = startroom(line);
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
	node->prev = cursor;
}

t_room	*endroom(char *str)
{
	char	**str1;
	t_room	*room;

	str1 = ft_strsplit(str, " ");
	room = initializeroom();
	room->name = str1[0];
	room->x = ft_atoi(str1[1]);
	room->y = ft_atoi(str1[2]);
	room->end = 1;
	return (room);
}

void	addendroom(t_room **roomlist, char *line)
{
	t_room	*node;
	t_room	*cursor;

	cursor = roomlist;
	node = endroom(line);
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
	node->prev = cursor;
}

t_room	*findroom(t_room **roomlist, char *str)
{
	t_room	*cursor;
	
	cursor = roomlist;
	while (cursor->next)
	{
		if (ft_strcmp(cursor->name, str) == 0)
			return (cursor);
		
	}
}


void	addlink(t_room **roomlist, char **str)
{
	int		i;
	t_room	*cursor;
	
	cursor = roomlist;
	(*roomlist)->connected = (t_room**)malloc(sizeof(t_room*) * (ft_listsize(*roomlist)) + 1);
	(*roomlist)->connected[(*roomlist)->links] = findroom(roomlist, str[0]);
	(*roomlist)->links++;
}	
