/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:56:08 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 18:02:11 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_link	*set_link(t_room *to, t_room *from)
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

void	room_link(t_hub *hub, char *line)
{
	t_room	*to;
	t_room	*from;
	char	**str;

	str = ft_strsplit(line, '-');
	to = find_room(&hub, str[0]);
	from = find_room(&hub, str[1]);
	addlink(&hub->links, set_link(to, from));
	free_array(str);
}
