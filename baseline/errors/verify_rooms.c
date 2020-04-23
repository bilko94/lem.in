/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:36:13 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 17:40:36 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	check_room(t_hub **hub, char *line)
{
	char	**str;

	str = ft_stsplit(line, " ");
	if (str[0] == 'L' || str[0] == 'l')
		room_error();
	if (str[0] == '#')
		room_error();
	if (ft_wordcount(line, " ") != 3)
		room_error();
}

void	room_error(void)
{
	ft_putendl_fd(RED "Error room name invalid" RESET, 2);
	exit (1);
}
