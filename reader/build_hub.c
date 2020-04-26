/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:27:09 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 18:04:15 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

t_hub	*build_hub(t_rd **data)
{
	t_hub	*hub;

	hub = init_hub();
	read_data(hub, data);
	return hub;
}

t_hub	*init_hub(void)
{
	t_hub	*new;
	
	if (!(new = (t_hub *)malloc(sizeof(t_hub))))
		return (false);
	new->end = NULL;
	new->start = NULL;
	new->linear = NULL;
	new->links = NULL;
	new->room_count = 0;
	new->ant_count = 0;
	new->path_count = 0;
	return (new);
}

int		check_ref(char *line)
{
	// if (ft_isdigit(line))
	// 	return (1);
	// else 
	if (line[0] == '#' && line[1] == '#')
		return (2);
	else if (line[0] == '#' && line[1] != '#')
		return (3);
	else if (ft_wordcount(line, ' ') == 3)
		return (4);
	else if (ft_wordcount(line, '-') == 2)
		return (5);
	else if (ft_isdigit(line[0]))
		return (1);
	// else
	return (6);
}

void	read_data(t_hub *hub, t_rd **data)
{
	t_rd	*current;
	int		ref;

	current = (*data);
	while (current)
	{
		// printf("%s\n", current->line);
		// ref = check_ref(current->line);
		add_data(hub, check_ref(current->line), current->line);
		if (ft_strcmp(current->line, "##start") == 0)
		{
			current = current->next;
			add_start_data(hub, current->line);
		}
		else if (ft_strcmp(current->line, "##end") == 0)
		{
			current = current->next;
			add_end_data(hub, current->line);
		}
		current = current->next;
	}
}

void	add_data(t_hub *hub, int ref, char *line)
{
	printf("ref %d\n", ref);
	if (ref == 1)
	{
		check_ants(line);
		hub->ant_count = ft_atoi(line);
	}
	if (ref == 2)
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			add_empty_room(hub, line, START);
			hub->room_count++;
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			add_empty_room(hub, line, END);
			hub->room_count++;
		}
		return ;
	}
	if (ref == 4)
	{
		printf("adding room\n");
		addroom(hub, line);
		hub->room_count++;
	}
	if (ref == 5)
	{
		// check_link(hub, line);
		// room_link(hub, line);
	}
	if (ref == 6)
	{
		check_line(hub, line);
		return ;
	}
	return ;
}
