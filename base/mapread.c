/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:59:23 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 18:02:43 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

void	start_map(void) //main
{
	t_rd	*data;
	t_hub	*hub;

	data = NULL;
	read_in(&data);
	hub = build_hub(&data);

}

void	printrooms(t_room *roomlist)
{
	t_room	*cursor;

	cursor = roomlist;
	while (cursor)
	{
		printf("\t\t%s\n", cursor->name);
		cursor = cursor->next;
	}
}
