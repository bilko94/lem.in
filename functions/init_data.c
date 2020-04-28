/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:10:05 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 18:04:20 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

void		read_in(t_rd **data){
	char	*line;

	while (get_next_line(0, &line)){
		add_rd_node(data, line);
		line = NULL;
	}
}

void		add_rd_node(t_rd **data, char *line){
	t_rd	*current;
	t_rd	*new;

	new = malloc_rd();
	new->line = line;
	current = (*data);
	if (!current)
		*data = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

int			init_build(t_hub **hub){
	t_rd *data = NULL;

	if (((*hub) = malloc_hub())){
		read_in(&(*hub)->raw_data);
		onetap((*hub));
		insert((*hub));
		onelink((*hub));
		relink(((*hub)));
		return 1;
	}
	return 0;
}

void relink(t_hub *hub){
	t_room *start = hub->room;
	t_room *temp = hub->room;
	t_room *start_room = NULL;

	if (hub->room->start == 1)
		return ;
	while (temp){
		if (temp->next)
			if (temp->next->start == 1){
				start_room = temp->next;
				temp->next = start_room->next;
				start_room->next = hub->room;
				hub->room = start_room;
				break ;
			}
		temp = temp->next;
	}
}