/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:53:53 by solivari          #+#    #+#             */
/*   Updated: 2019/09/12 14:20:09 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// void	createroom(char **str)
// {
// 	t_room	*room;

// 	if (!(room = (t_room*)malloc(sizeof(t_room))))
// 		return ;
// 	room->name = str[0];
// 	room->x = ft_atoi(str[1]);
// 	room->y = ft_atoi(str[2]);
// 	room->links = 0;
// 	room->connected = NULL;
// 	room->next = NULL;
// 	room->prev = NULL;
// 	room->start = 0;
// 	room->end = 0;
// }

t_room	*createhead(t_room **roomlist)
{
	(*roomlist) = initializeroom();
	return (*roomlist);
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

// t_room	*startroom(char *str)
// {
// 	char	**str1;
// 	t_room	*room;

// 	str1 = ft_strsplit(str, " ");
// 	room = initializeroom();
// 	room->name = str1[0];
// 	room->x = ft_atoi(str1[1]);
// 	room->y = ft_atoi(str1[2]);
// 	room->start = 1;
// 	return (room);
// }

void	addstartroom(t_room **roomlist, char *line)
{
	t_room	*node;
	t_room	*cursor;

	cursor = (*roomlist);
	node = room(line);
	node->start = 1;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
	node->prev = cursor;
}

t_room	*room(char *str)
{
	char	**str1;
	t_room	*room;

	str1 = ft_strsplit(str, ' ');
	room = initializeroom();
	room->name = str1[0];
	room->x = ft_atoi(str1[1]);
	room->y = ft_atoi(str1[2]);
	return (room);
}

void	addendroom(t_room **roomlist, char *line)
{
	t_room	*node;
	t_room	*cursor;

	cursor = (*roomlist);
	node = room(line);
	node->end = 1;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
	node->prev = cursor;
}

void	addroom(t_room **roomlist, char *line)
{
	t_room	*node;
	t_room	*cursor;

	cursor = (*roomlist);
	node = room(line);
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
	node->prev = cursor;
}

t_room	*findroom(t_room **roomlist, char *str)
{
	t_room	*cursor;
	
	cursor = (*roomlist);
	while (cursor->next)
	{
		if (ft_strcmp(cursor->name, str) == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

void	addlink(t_room **roomlist, char **str)
{
	t_room	*cursor;
	
	cursor = (*roomlist);
	(*roomlist)->connected = (t_room**)malloc(sizeof(t_room*) * (ft_list_size(*roomlist)) + 1);
	(*roomlist)->connected[(*roomlist)->links] = findroom(roomlist, str[0]);
	(*roomlist)->links++;
}	
