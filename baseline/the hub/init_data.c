/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:10:05 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 18:04:20 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		read_in(t_rd **data)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		add_rd_node(data, line);
		free(line);
	}
}

void		add_rd_node(t_rd **data, char *line)
{
	t_rd	*current;
	t_rd	*new;

	new = init_rd();
	new->line = ft_strdup(line);
	current = (*data);
	if (!current)
		*data = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}	
}

t_rd	*init_rd(void)
{
	t_rd	*new;

	if (!(new = (t_rd *)malloc(sizeof(t_rd))))
		return (false);
	new->line = NULL;
	new->next = NULL;
	return (new);
}
