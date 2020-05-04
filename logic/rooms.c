/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 16:29:01 by solivari          #+#    #+#             */
/*   Updated: 2020/04/24 16:29:01 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

int     addroutelistnode(t_routelist **routelist, int id)
{
    t_routelist *newnode;
    t_routelist *curnode;

    curnode = *routelist;
    while (curnode && curnode->next)
        curnode = curnode->next;
    if (!(newnode = (t_routelist*)malloc(sizeof(t_routelist))))
        return (0);
    newnode->id = id;
    newnode->route = NULL;
    newnode->ants = 0;
    newnode->next = NULL;
    if (*routelist)
        curnode->next = newnode;
    else
        *routelist = newnode;
    return (1);
}

int    addroute(t_route **route, t_room *room)
{
    t_route  *curroom;
    t_route  *newroom;

    curroom = *route;
    while (curroom && curroom->next)
        curroom = curroom->next;
    if (!(newroom = (t_route*)malloc(sizeof(t_route))))
        return (0);
    newroom->room = room;
    newroom->next = NULL;
    if (*route)
        curroom->next = newroom;
    else
        *route = newroom;
    return (1);
}

void    assessqueue(t_queue **q, t_roomids *roomids, t_route **curroute)
{
    t_roomids      *tmpids;
    t_route        *tmproute;

    if (q)
    {
        tmpids = roomids;
        while (tmpids && tmpids->next && (tmpids->id != (*q)->room->id))
            tmpids = tmpids->next;
        (*q)->room->visited = 0;
        if (tmpids && (tmpids->id == (*q)->room->id))
        {
            tmproute = *curroute;
            while (tmproute && (tmproute->room->id != (*q)->room->id))
                tmproute = tmproute->next;
            if (!tmproute){
                addroute(curroute, (*q)->room);
                printf("added route for %d\n", (*q)->room->id);
            }
            if (!((*q)->room->start || (*q)->room->end))
                (*q)->room->visited = 1;
        }
        if ((*q)->next)
            assessqueue(&((*q)->next), roomids, curroute);
        free((*q));
        *q = NULL;
    }
}

void    addtoqueue(t_queue **q, t_queue *parent, t_room *room)
{
    t_queue *curq;
    t_queue *newq;

    curq = *q;
    while (curq && curq->next){
        curq = curq->next;
    }
    newq = (t_queue*)malloc(sizeof(t_queue));
    newq->next = NULL;
    newq->parent = parent ? parent : NULL;
    newq->room = room;
    if (*q)
        curq->next = newq;
    else
        *q = newq;
}