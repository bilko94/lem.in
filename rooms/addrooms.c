/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addrooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:53:53 by solivari          #+#    #+#             */
/*   Updated: 2019/09/16 17:24:00 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	addstartroom(t_room **roomlist, char *line)
{
	t_room	*node;
	t_room	*cursor;

	cursor = (*roomlist);
	node = set_room(line);
	node->start = 1;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
}

void	addendroom(t_room **roomlist, char *line)
{
	t_room	*node;
	t_room	*cursor;

	cursor = (*roomlist);
	node = set_room(line);
	node->end = 1;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
}

void	addroom(t_room **roomlist, char *line)
{
	t_room	*node;
	t_room	*cursor;

	cursor = (*roomlist);
	node = set_room(line);
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
}
