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

#include "../global.h"

void	add_empty_room(t_hub *hub, char *line, int identifier)
{
	t_room	*node;
	t_room *cursor;
	
	cursor = hub->start;
	printf("setting up cursor\n");
	node = init_room();
	printf("room constructed\n");
	if (identifier == 1)
		node->start = 1;
	else if (identifier == 2)
		node->end = 1;
	printf("node setup\n");
	if (cursor){
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = node;
		printf("found end\n");
	} else 
		hub->linear = node;
	printf("node placed\n");
}

void	addroom(t_hub *hub, char *line)
{
	t_room	*node;
	t_room	*cursor;

	cursor = hub->linear;
	printf("setting up cursor\n");
	node = set_room(line);
	printf("room constructed\n");
	if (cursor){
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = node;
		printf("found end\n");
	} else 
		hub->linear = node;
	printf("node placed\n");
}
