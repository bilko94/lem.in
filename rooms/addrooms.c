/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addrooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:53:53 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 18:03:58 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	add_empty_room(t_hub **hub, char *line, int identifier)
{
	t_room	*node;
	t_room *cursor;
	
	cursor = (*hub)->linear;
	node = init_room();
	if (identifier == 1)
		node->start = 1;
	else if (identifier == 2)
		node->end = 1;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
}

void	addroom(t_hub **hub, char *line)
{
	t_room	*node;
	t_room	*cursor;

	cursor = (*hub)->linear;
	node = set_room(line);
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
}

// void	addstartroom(t_hub **hub, char *line)
// {
// 	t_room	*node;
// 	t_room	*cursor;

// 	cursor = (*hub)->linear;
// 	node = set_room(line);
// 	node->start = 1;
// 	while (cursor->next)
// 		cursor = cursor->next;
// 	cursor->next = node;
// 	(*hub)->start = node;
// }

// void	addendroom(t_hub **hub, char *line)
// {
// 	t_room	*node;
// 	t_room	*cursor;

// 	cursor = (*hub)->linear;
// 	node = set_room(line);
// 	node->end = 1;
// 	while (cursor->next)
// 		cursor = cursor->next;
// 	cursor->next = node;
// 	(*hub)->end = node;
// }
