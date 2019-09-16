/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:27:09 by solivari          #+#    #+#             */
/*   Updated: 2019/09/16 17:35:42 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_hub	*build_hub(t_rd **data)
{
	t_hub	*hub;

	hub = init_hub();
	read_data(hub, data);
	
}

void	*init_hub(void)
{
	t_hub	*new;
	
	if (!(new = (t_hub*)malloc(sizeof(t_hub))))
		return (false);
	new->end = NULL;
	new->start = NULL;
	new->linear = NULL;
	new->links = NULL;
	new->room_count = 0;
	return (new);
}

void	read_data(t_hub *hub, t_rd **data)
{
	t_rd	*current;
	
}