/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:59:23 by solivari          #+#    #+#             */
/*   Updated: 2019/09/12 15:44:44 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_rd	*create_node(char *line)
{
	t_rd	*node;

	if (!(node = (t_rd *)malloc(sizeof(t_rd))))
		return (NULL);
	node->name = NULL;
	node->x = 0;
	node->y = 0;
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
// 	printf("%s\n", line);
}

void	readmap(t_rd **rd)
{
	int		i;
	t_rd	*cursor;
	
	i = 0;
	cursor = (*rd);
	while (cursor->next)
	{
		if (testcase(cursor->line) == 0)
			EREXIT ;
		cursor = cursor->next;
	}
}

t_rd	*initialize(t_rd **rd)
{
	t_rd	*new;

	if (!(new = (t_rd *)malloc(sizeof(t_rd) + 1)))
		return (NULL);
	new->name = NULL;
	new->x = 0;
	new->y = 0;
	new->dx = 0;
	new->next = NULL;
	new->prev = NULL;
	if (!(new->line = malloc(1)))
		return (NULL);
	(*rd) = new;
	return (*rd);
}

void	checkmap(void) //main
{
    int		ret;
    int		fd;
    int		j;
	t_rd	*rd;
	t_rd	*cursor;
	t_room	*roomlist;

	rd = initialize(&rd);
	cursor = rd;
	roomlist = createhead(&roomlist);
	ret = 0;
	fd = 0;
	j = 1;
	while ((ret = get_next_line(fd, &cursor->line)) > 0)
	{
		// printf("\t\t%s\n", cursor->line);
		addnode(&rd, cursor->line);
	}
	printstack(&rd);
	map(&rd, &roomlist);
}	

void	map(t_rd **rd, t_room **roomlist)
{
	t_rd	*cursor;
	int		ants;
	char	**str;
	
	cursor = (*rd);
	ants = ft_atoi(cursor->line);
	printf("ants = %d\n", ants);
	cursor = cursor->next;
	printf("here\n");
	while (cursor->next)
	{
		if (ft_strcmp(cursor->line, "##start") == 0)
		{
			printf("here1\n");
			cursor = cursor->next;
			addstartroom(roomlist, cursor->line);
		}
		else if (ft_strcmp(cursor->line, "##end") == 0)
		{
			printf("here2\n");
			cursor = cursor->next;
			addendroom(roomlist, cursor->line);
		}
		else if (ft_arraylen(ft_strsplit(cursor->line, ' ')) == 3 && \
		((str = ft_strsplit(cursor->line, ' ')) && (ft_strcmp(str[0], "#") != 0 || ft_strcmp(str[0], "##"))))
		{
			printf("here2\n");
			addroom(roomlist, cursor->line);
		}
		else if (ft_arraylen(ft_strsplit(cursor->line, '-')) == 2)
		{
			printf("here2\n");
			addlink(roomlist, ft_strsplit(cursor->line, '-'));
		}
		printf("cycle\n");
		cursor = cursor->next;
	}
}
