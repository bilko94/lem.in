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
		purge_t_queue(freeq);
        return (0);
    }
    // printf("q->room->end: %d therefore now moving to assessqueue on success\n", q->room->end);
    roomids = NULL;
    while (q->parent){
        addroomid(q->room->id, &roomids);
        // printf("roomid: %d added to id list\n", q->room->id);
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
    // assessqueue(&freeq, NULL, &(routelist->route));
    freeroomids(&roomids);
	purge_t_queue(freeq);
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
    int             loop;
    t_routelist     *routelist;
    t_routelist     *temp;
	t_route			*temproute;

    n = 0;
	i = why();
    while(1){
        addroutelistnode(&hub->routelist, ++i);
        // printf("added first node for routelist\n");
        routelist = hub->routelist;
        while (routelist->next)
            routelist = routelist->next;
        if (!search(hub, routelist)){
			deleteroute();
            break;
		}
    }
	end_break();
    performance_meter('a');
}

void deleteroute(){
	t_routelist *temp = hub(0)->routelist;
	while (temp){
		if (temp->next){
			if (!temp->next->route){
				free(temp->next);
				temp->next = NULL;
			}
		}
		temp = temp->next;
	}
}

int why(){
	if (end_link()){
		addroutelistnode(&hub(0)->routelist, 1);
		addroute(&hub(0)->routelist->route, hub(0)->room);
		addroute(&hub(0)->routelist->route, end_room());
		end_break();
		return (1);
	}
	return (0);
}

t_room *end_room(){
	t_room *temp = hub(0)->room;
	while (temp){
		if (temp->end == 1)
			return temp;
		temp = temp->next;
	}
	return (NULL);
}

int end_link(){
	t_link *links = hub(0)->room->links;
	while (links){
		if (links->linked_room->end == 1)
			return (1);
		links = links->next;
	}
	return (0);
}

void end_break(){
    static t_link *end;
    t_room *start = hub(0)->room;
    t_link *temp = NULL;
    t_link *prev = NULL;
    if (!end){
        if (start->links){
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
        }
        return ;
    } else {
        end->next = start->links;
        start->links = end;
    }
}
