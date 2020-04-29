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

void    addroomid(int id, t_roomids **roomids)
{
    t_roomids *newnode;
    t_roomids *curnode;

    curnode = *roomids;
    while (curnode && curnode->next)
        curnode = curnode->next;
    newnode = (t_roomids*)malloc(sizeof(t_roomids));
    newnode->id = id;
    newnode->next = NULL;
    if (*roomids)
        curnode->next = newnode;
    else
        *roomids = newnode;
}

void    freeroomids(t_roomids **roomids)
{
    if ((*roomids)->next)
        freeroomids(&(*roomids)->next);
    free(*roomids);
}

int     search(t_hub *hub, t_routelist *routelist)
{
    t_queue     *q;
    t_roomids   *roomids;

    q = NULL;
    addtoqueue(&q, NULL, hub->room);
    printf("queue created\n");
    while (q && !q->room->end)
    {
        printf("checking for end: %d\n", q->room->end);
        while (q->room->links && q->room->links->next)
        {
            if (!q->room->links->visited){
                addtoqueue(&q, q, q->room->links)
                pritnf("added %d to queue\n", q->room->id);
            }
            q->room->links = q->room->links->next;
        }
        if (!q->room->end)
            break ;
        q = q->next;
    }
    if (!q->room->end)
    {
        freequeue(&q, NULL, &(routelist->route));
        return (0);
    }
    roomids = NULL;
    while (q->parent)
    {
        addroomid(q->room->id, &roomids);
        q = q->parent;
    }
    addroomid(q->room->id, &roomids);
    freequeue(&q, roomids, &(routelist->route));
    freeroomids(&roomids);
    return 1;
}

int     bfs(t_hub *hub)
{
    int             i;
    t_routelist     *routelist;

    i = 0;
    while(1)
    {
        addroutelistnode(&hub->routelist, ++i);
        printf("added first node for routelist\n")
        routelist = hub->routelist;
        while (routelist->next)
            routelist = routelist->next;
        printf("search\n");
        if (!search(hub, routelist))
            break;
    }
    printf("Route creation error\n");
}