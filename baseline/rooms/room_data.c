/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:47:43 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 16:06:54 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	add_start_data(t_hub **hub, char *line)
{
	t_room	*cursor;
	char	**str;

	str = ft_strsplit(line, " ");
	cursor = (*hub)->linear;
	while (cursor->next && cursor->start != 1)
		cursor = cursor->next;
	cursor->name = str[0];
	cursor->x = ft_atoi(str[1]);
	cursor->y = ft_atoi(str[2]);
	(*hub)->start = cursor;
	free(str);
}

void	add_end_data(t_hub **hub, char *line)
{
	t_room	*cursor;
	char	**str;

	str = ft_strsplit(line, " ");
	cursor = (*hub)->linear;
	while (cursor->next && cursor->end != 1)
		cursor = cursor->next;
	cursor->name = str[0];
	cursor->x = ft_atoi(str[1]);
	cursor->y = ft_atoi(str[2]);
	(*hub)->end = cursor;
	free(str);
}
