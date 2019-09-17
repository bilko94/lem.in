/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:59:23 by solivari          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/09/17 09:34:42 by solivari         ###   ########.fr       */
=======
/*   Updated: 2019/09/16 17:46:25 by solivari         ###   ########.fr       */
>>>>>>> e3204dff0a27cb77af5ffb01a6c8607a01b7ef2c
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	start_map(void) //main
{
	t_rd	*data;
	t_hub	*hub;

	data = NULL;
	read_in(&data);
	hub = build_hub(&data);
	// rd = initialize_rd(&rd);
	// cursor = rd;
	// roomlist = createhead(&roomlist);
	// printstack(&rd);
	// map(&rd, &roomlist);
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

int		line_type(char *line)
{
<<<<<<< HEAD
	char	**split;
	char	**split1;
	int		count;
	int		count1;

	split = ft_strsplit(line, '-');
	count = ft_arraylen(split);
	split1 = ft_strsplit(line, " ");
	count1 = ft_arraylen(split1);
	if (ft_isdigit(line) && count == 1)
		return (1);
	if (line[0] == '#' && line[1] == '#')
		return (2);
	if (line[0] == '#' && line[1] != '#')
		return (3);
	if (count1 == 3)
		return (4);
	if (count == 2)
		return (5);
	free(split);
	free(split1);
	return (6);
=======
	if ()
>>>>>>> e3204dff0a27cb77af5ffb01a6c8607a01b7ef2c
}

void	map(t_hub *hub, t_rd **data)
{
	t_rd	*current;
	int		ref;

	ref = 0;
	current = (*data);
	while (current)
	{
		ref = line_type(current->line);
<<<<<<< HEAD
		if (ref == 1)
			
=======
		if ()
>>>>>>> e3204dff0a27cb77af5ffb01a6c8607a01b7ef2c
	}
	// t_rd	*current;
	// int		ants;
	// char	**str;
	
	// current = (*data);
	// ants = ft_atoi(current->line);
	// current = current->next;
	// while (cursor->next)
	// {
	// 	if (ft_strcmp(cursor->line, "##start") == 0)
	// 	{
	// 		cursor = cursor->next;
	// 		addstartroom(roomlist, cursor->line);
	// 	}
	// 	else if (ft_strcmp(cursor->line, "##end") == 0)
	// 	{
	// 		cursor = cursor->next;
	// 		addendroom(roomlist, cursor->line);
	// 	}
	// 	else if (ft_arraylen(ft_strsplit(cursor->line, ' ')) == 3 && \
	// 	((str = ft_strsplit(cursor->line, ' ')) && (ft_strcmp(str[0], "#") != 0 || ft_strcmp(str[0], "##"))))
	// 	{
	// 		addroom(roomlist, cursor->line);
	// 	}
	// 	else if (ft_arraylen(ft_strsplit(cursor->line, '-')) == 2)
	// 	{
	// 		addlink(roomlist, ft_strsplit(cursor->line, '-'));
	// 	}
	// 	cursor = cursor->next;
	// }
	// printrooms(*roomlist);
}
