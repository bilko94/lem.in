/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:56:08 by solivari          #+#    #+#             */
/*   Updated: 2019/09/16 15:57:21 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_link	*init_link(void)
{
	t_link	*new;

	if (!(new = malloc(sizeof(t_link))))
		return (NULL);
	new->to = NULL;
	new->from = NULL;
	new->next = NULL;
	return (new);
}

t_link	*set_link(t_room *from, t_room *to)
{
	t_link	*new;

	if (!(new = malloc(sizeof(t_link))))
		return (NULL);
	new->to = to;
	new->from = from;
	new->next = NULL;
	return (new);
}

void	addlink(t_link **list, t_link *new)
{
	t_link 	*link;
	
	link = list;
	if (!link)
		link = new;
	else
	{
		while (link->next)
			link = link->next;
		link->next = new;
	}
}
