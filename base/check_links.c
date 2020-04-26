/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:15:52 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 17:30:18 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

void	check_link(t_hub *hub, char *line)
{
	char	**str;

	str = ft_strsplit(line, '-');
	if (strcmp(str[0], str[1]) == 0)
		link_error();
	if (find_room(hub->start, str[0]) == NULL || find_room(hub->start, str[1]) == NULL)
		link_error();
	free_array(str);
}

void	link_error(void)
{
	ft_putendl_fd(RED "Error invalid room links\n" RESET, 2);
	exit (1);
}
