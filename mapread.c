/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:59:23 by solivari          #+#    #+#             */
/*   Updated: 2019/09/10 17:35:41 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_rd	*create_node(char *line)
{
	t_rd	*node;

	if (!(node = (t_rd *)malloc(sizeof(t_rd))))
		return (NULL);
	node->name = NULL;
	node->x = NULL;
	node->y = NULL;
	node->line = line;
	node->dx = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	addnode(t_rd **rd, char *line)
{
	t_rd	*node;
	t_rd	*cursor;

	cursor = (*rd);
	node = create_node(line);
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
	node->prev = cursor;
}

void	executecmd(char *str, t_rd **rd)
{
	
}

void	split(char *av, t_rd **rd)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_strsplit(av, ' ');
	executecmd(split, rd);
	while (split[j])
		free(split[j++]);
	free(split);
}

void	readmap(t_rd **rd)
{
	int		i;
	t_rd	*cursor;
	
	i = 0;
	cursor = rd;
	while (cursor->next)
	{
		if (testcase(cursor))
	}
}


t_rd	*initialize(void)
{
	t_rd	*new;

	if (!(new = (t_rd *)malloc(sizeof(t_rd) + 1)))
		return (NULL);
	new->name = NULL;
	new->x = NULL;
	new->y = NULL;
	new->dx = 0;
	new->next = NULL;
	new->prev = NULL;
	new->line = malloc(1);
	return (new);
}

void	checkmap(void)
{
    int		ret;
    int		fd;
    int		j;
	t_rd	**rd;

	rd = initialize();
	ret = 0;
	fd = 0;
	j = 1;
	if (!((*rd)->line = malloc(1)))
		return (NULL);
	while (ret = get_next_line(fd, &(*rd)->line) > 0)
		addnode(&rd, (*rd)->line);
	readmap(&rd);
}