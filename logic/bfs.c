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

int    addroomid(int id, t_roomids **roomids)
{
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

void	freeroomids(t_roomids **roomids)
{
	if ((*roomids)->next)
		freeroomids(&(*roomids)->next);
	free(*roomids);
}

int     search(t_hub *hub, t_routelist *routelist)
{
    t_queue     *q;
    t_queue     *freeq;
    t_roomids   *roomids;
    t_link      *tmplink;

    q = NULL;
    hub->queue = q;
    addtoqueue(&q, NULL, hub->room);
    freeq = q;
    // printf("queue created\n");
    while (q && !(q->room->end))
	{
        // printf("-->checking for end: %d\n", q->room->end);
        // printf("-->checking for start: %d\n", q->room->start);
        // printf("room id: %d -- visited?: %d\n", q->room->id, q->room->visited);
        // printf("room links exists: %d\n", q->room->links ? 1:0);
        tmplink = q->room->links;
        while (tmplink)
        {
            // printf("->visited current room?: %d\n", q->room->visited);
            // printf("->linked room id: %d visited: %d\n", q->room->links->linked_room->id, q->room->links->linked_room->visited);
            if (!tmplink->linked_room->visited){
                addtoqueue(&q, q, tmplink->linked_room);
                // printf("added %d to queue\n", q->room->links->linked_room->id);
            }
            tmplink = tmplink->next;
        }
        // printf("you are currently at roomid: %d\n", q->room->id);
        if (!q->next || q->room->end){
            // printf("###either end: %d or no next available\n", q->room->end);
            break ;
        }
        q = q->next;
    }
    // printf("after while loop\n");
    if (!q->room->end)
    {
        // printf("q->room->end was false, now running assessqueue for failure\n");
        assessqueue(&q, NULL, &(routelist->route));
        return (0);
    }
    // printf("q->room->end: %d therefore now moving to assessqueue on success\n", q->room->end);
    roomids = NULL;
    while (q->parent){
        addroomid(q->room->id, &roomids);
        // printf("roomid: %d added to id list\n", q->room->id);
        q = q->parent;
    }
    addroomid(q->room->id, &roomids);
    assessqueue(&freeq, roomids, &(routelist->route));
    // assessqueue(&freeq, NULL, &(routelist->route));
    freeroomids(&roomids);
    return (1);
}

void    poproute(t_routelist *routelist)
{
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

int     bfs(t_hub *hub)
{
    int             i;
    t_routelist     *routelist;
    t_routelist     *temp;
	t_route			*temproute;

    i = 0;
    while(1){
        addroutelistnode(&hub->routelist, ++i);
        // printf("added first node for routelist\n");
        routelist = hub->routelist;
        if (route_len(routelist->route) == 2){
            printf("route: %d, %d are start: %d and end: %d\n", route->room->id, route->next->room->id, route->room->start, route->room->end);
            break;
        }
        while (routelist->next)
            routelist = routelist->next;
        // printf("search\n");
        if (!search(hub, routelist))
            break;
    }
    // printf("end of while loop\n");
    temp = hub->routelist;
    while (temp){
		temproute = temp->route;
        while (temproute){
            // printf("route goes: %d\n",temproute->room->id);
            temproute = temproute->next;
        }
        temp = temp->next;
    }
	// printf("instructions:%d\n\n #### debug output finished ####\n\n",mover());
}
