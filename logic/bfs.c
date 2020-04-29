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
    while (q && !(q->room->end))
    {
        printf("checking for end: %d\n", q->room->end);
        while (q->room->links)
        {
            printf("visited current room?: %d\n", q->room->visited);
            printf("visited linked room?: %d\n", q->room->links->linked_room->visited);
            printf("room id: %d -- visited?: %d\n", q->room->id, q->room->visited);
            if (!q->room->links->linked_room->visited){
                addtoqueue(&q, q, q->room->links->linked_room);
                printf("added %d to queue\n", q->room->links->linked_room->id);
            }
            q->room->links = q->room->links->next;
        }
        if (!q->next || q->room->end){
            printf("###either end: %d or no next available\n", q->room->end);
            break ;
        }
        q = q->next;
    }
    printf("after while loop\n");
    if (!q->room->end)
    {
        printf("q->room->end was false, now running assessqueue for failure\n");
        assessqueue(&q, NULL, &(routelist->route));
        return (0);
    }
    printf("after assesqueue on not finding room end\n");
    roomids = NULL;
    while (q->parent)
    {
        addroomid(q->room->id, &roomids);
        q = q->parent;
    }
    addroomid(q->room->id, &roomids);
    assessqueue(&q, roomids, &(routelist->route));
    freeroomids(&roomids);
    return 1;
}

int     bfs(t_hub *hub)
{
    int             i;
    t_routelist     *routelist;
    t_routelist     *temp;

    i = 0;
    while(1)
    {
        addroutelistnode(&hub->routelist, ++i);
        printf("added first node for routelist\n");
        routelist = hub->routelist;
        while (routelist->next)
            routelist = routelist->next;
        printf("search\n");
        if (!search(hub, routelist))
            break;
    }
    printf("end of while loop\n");
    temp = hub->routelist;
    while (temp){
        while (temp->route){
            printf("route goes: %d\n", temp->route->room->id);
            temp->route = temp->route->next;
        }
        temp = temp->next;
    }
}