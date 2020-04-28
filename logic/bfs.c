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

int     bfs(t_hub *hub)
{
    int     i;
    t_room   *room;

    i = 0;
    while(1)
    {
        addroomnode(&hub->room, ++i);
        room = hub->room;
        while (room->next)
            room = room->next;
        if (!search(hub, room))
            break;
    }
    
}