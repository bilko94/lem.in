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

int     addroomnode(t_room **room, int id)
{
    t_room *newnode;
    t_room *curnode;

    curnode = *roomids;
    while (curnode && curnode->next)
        curnode = curnode->next;
    if (!(newnode = (t_room*)malloc(sizeof(t_roomids))))
        return (0)
    newnode->id = id;
    newnode->visited = 0;
    newnode->next = NULL;
    if (*room)
        curnode->next = newnode;
    else
        *room = newnode;
    return (1);
}

