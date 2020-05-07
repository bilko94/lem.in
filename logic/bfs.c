/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 15:48:45 by solivari          #+#    #+#             */
/*   Updated: 2020/04/24 15:48:45 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

int    addroomid(int id, t_roomids **roomids){
    t_roomids *newnode;
    t_roomids *curnode;

    curnode = *roomids;
    while (curnode && curnode->next)
        curnode = curnode->next;
    if (!(newnode = (t_roomids*)malloc(sizeof(t_roomids))))
        return (0);
    newnode->id = id;
    newnode->next = NULL;
    if (*roomids)
        curnode->next = newnode;
    else
        *roomids = newnode;
    return (1);
}

void	freeroomids(t_roomids **roomids){
	if ((*roomids)->next)
		freeroomids(&(*roomids)->next);
	free(*roomids);
}

int     search(t_hub *hub, t_routelist *routelist){
    t_queue     *q;
    t_queue     *freeq;
    t_roomids   *roomids;
    t_link      *tmplink;

    q = NULL;
    hub->queue = q;
    addtoqueue(&q, NULL, hub->room);
    freeq = q;
    while (q && !(q->room->end)){
        tmplink = q->room->links;
        while (tmplink){
            if (!tmplink->linked_room->visited){
                addtoqueue(&q, q, tmplink->linked_room);
            }
            tmplink = tmplink->next;
        }
        if (!q->next || q->room->end){
            break ;
        }
        q = q->next;
    }
    if (!q->room->end){
        assessqueue(&q, NULL, &(routelist->route));
		purge_t_queue(freeq);
		q = NULL;
        return (0);
    }
    roomids = NULL;
    while (q->parent){
        addroomid(q->room->id, &roomids);
        q = q->parent;
    }
    addroomid(q->room->id, &roomids);
    assessqueue(&freeq, roomids, &(routelist->route));
    freeroomids(&roomids);
	purge_t_queue(freeq);
	freeq = NULL;
    return (1);
}

void    poproute(t_routelist *routelist){
    t_routelist     *prev;

    prev = NULL;
    while (routelist && routelist->next)
    {
        prev = routelist;
        routelist = routelist->next;
    }
    if (routelist)
        free(routelist);
    if (prev)
        prev->next = NULL;
}

int     bfs(t_hub *hub){
    int             i;
    int             n;
    t_routelist     *routelist;
    t_routelist     *temp;
	t_route			*temproute;

    i = 0;
    n = 0;
    while(n != 2){
        addroutelistnode(&hub->routelist, ++i);
        routelist = hub->routelist;
        printf("routelen: %d\n", route_len(routelist->route));
        if (route_len(routelist->route) == 2){
            printf("route: %d, %d are start: %d and end: %d\n", routelist->route->room->id, routelist->route->next->room->id, routelist->route->room->start, routelist->route->room->end);
            break;
        }
        while (routelist->next)
            routelist = routelist->next;
        if (!search(hub, routelist))
            break;
        n += 1;
    }
}

void end_break(){
	static t_link *end;
	t_room *start = hub(0)->room;
	t_link *temp = NULL;
	t_link *prev = NULL;
	if (!end){
		if (start->links->linked_room->end == 1){
			end = start->links;
			start->links = end->next;
		} else {
			temp = start->links;
			while (temp){
				if (temp->linked_room->end == 1){
					end = temp;
					prev->next = end->next;
				}
				prev = temp;
				temp = temp->next;
			}
		}
		return ;
	} else {
		end->next = start->links;
		start->links = end;
	}
}
