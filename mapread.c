/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:59:23 by solivari          #+#    #+#             */
/*   Updated: 2019/09/11 17:29:45 by solivari         ###   ########.fr       */
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
}

void	executecmd(char **str, char c)
{
	int i;
	
	i = 0;
	if (c == '-')
		createlink(str);
	else if (c == ' ')
	{
		
		createroom(str);
	}
}

void	split(char *av, char c)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_strsplit(av, c);
	executecmd(split, c);
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
		if (testcase(cursor->line) == 0)
			EREXIT ;
		cursor = cursor->next;
	}
}

t_rd	*initialize(void)
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
	return (new);
}

void	checkmap(void) //main
{
    int		ret;
    int		fd;
    int		j;
	int		ants;
	t_rd	**rd;
	t_rd	*cursor;
	t_room	**roomlist;

	rd = initialize();
	roomlist = initializeroom();
	ret = 0;
	fd = 0;
	j = 1;
	while (ret = get_next_line(fd, &(*rd)->line) > 0)
		addnode(&rd, (*rd)->line);
	readmap(&rd);
	cursor = rd;
	ants = ft_atoi(cursor->line);
	cursor = cursor->next;
	while (cursor->next)
	{
		if (strcmp(cursor->line, "##start") == 0)
			addstartroom(&roomlist, cursor->next->line);
		else if (strcmp(cursor->line, "##end") == 0)
			addendroom(&roomlist, cursor->next->line);
		else if (ft_arraylen(ft_strsplit(cursor->line, " ")) == 3)
			addroom(&roomlist, cursor->line);
		else if (ft_arraylen(ft_strsplit(cursor->line, "-")) == 2)
			addlink(&roomlist, ft_strsplit(cursor->line, '-'));
	}
}