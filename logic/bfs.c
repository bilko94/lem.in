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
    // if (q->parent->room->start && q->room->end){
    //     addroomid(q->room->id, &roomids);
    //     assessqueue(&freeq, roomids, &(routelist->route));
    //     freeroomids(&roomids);
    //     return (0);
    // }
    addroomid(q->room->id, &roomids);
    assessqueue(&freeq, roomids, &(routelist->route));
    freeroomids(&roomids);
	purge_t_queue(freeq);
	freeq = NULL;
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

int     link_count(t_room *room){
    t_room  *temp;
    int     i;

    i = 0;
    temp = room;
    while (temp->links){
        i++;
        temp->links = temp->links->next;
    }
    return (i);
}

int     bfs(t_hub *hub)
{
    int             i;
    int             n;
    t_routelist     *routelist;
    t_routelist     *temp;
	t_route			*temproute;
    t_room          *infiniteloop;


    i = 0;
    n = 0;
    infiniteloop = hub->room;
    while(1){
        addroutelistnode(&hub->routelist, ++i);
        routelist = hub->routelist;
        if (route_len(routelist->route) == 2){
            if (link_count(infiniteloop) > 1 && infiniteloop->start){
                printf("links = %d\n", link_count(hub->room));
                // unlink();
                infiniteloop = infiniteloop->next;
            }
            else {
                printf("route: %d, %d are start: %d and end: %d\n", routelist->route->room->id, routelist->route->next->room->id, routelist->route->room->start, routelist->route->next->room->end);
                break;
            }
        }
        while (routelist->next){
            routelist = routelist->next;
        }
        // printf("search\n");
        if (!search(hub, routelist))
            break;
    }
    // printf("end of while loop\n");
    temp = hub->routelist;
    while (temp){
		temproute = temp->route;
        printf("routelen: %d\n", route_len(temp->route));
        while (temproute){
            printf("route goes: %d\n",temproute->room->id);
            temproute = temproute->next;
        }
        temp = temp->next;
    }
	// printf("instructions:%d\n\n #### debug output finished ####\n\n",mover());
}

