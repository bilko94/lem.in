/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:37:17 by solivari          #+#    #+#             */
/*   Updated: 2019/09/16 16:37:31 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		countrooms(void)
{
	char	*line;
	int		nb_rooms;
	int		words;

	nb_rooms = 0;
	words = 0;
	while (get_next_line(0, &line))
	{
		if ((words = wordcount(line, ' ')) == 3)
			nb_rooms += 1;
		free(line);
	}
	return (nb_rooms);
}
