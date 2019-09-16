/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:17:55 by solivari          #+#    #+#             */
/*   Updated: 2019/09/16 17:44:53 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft/libft.h"
# define EREXIT err()

typedef struct		s_rd
{
	char			*line;
	struct s_rd		*next;
}					t_rd;

typedef struct		s_room
{
	int				x;
	int				y;
	int				link_count;
	char			*name;
	struct s_room	**links; // = (t_room**)malloc(sizeof(t_room*) * nb of rooms + 1);
	struct s_room	*next;
	bool			occupied;
	bool			start;
	bool			end;
}					t_room;
// ex. line = 5-2
// char **connected[links] = find.room.by.name(data[1]);
// links++;

typedef struct		s_link
{
	t_room			*to;
	t_room			*from;
	struct s_link	*next;
}					t_link;

typedef struct		s_hub
{
	t_link			*links;
	t_room			*linear;
	t_room			*start;
	t_room			*end;
	int				room_count;
}					t_hub;

//Mapping

void	start_map(void);
void	readmap(t_rd **rd);
void	read_in(t_rd **data);
t_rd	*init_rd(void);
void	add_rd_node(t_rd **data, char *line);
void	map(t_hub *hub, t_rd **data);
// t_rd	*create_rd_node(char *line);
// void	addnode(t_rd **rd);

//Rooms

t_room	*createhead(t_room **roomlist);
t_room	*init_room(void);
t_room	*set_room(char *str);
t_room	*findroom(t_room **roomlist, char *str);
void	addendroom(t_room **roomlist, char *line);
void	addstartroom(t_room **roomlist, char *line);
void	addroom(t_room **roomlist, char *line);

//Links

t_link	*init_link(void);
t_link	*set_link(t_room *from, t_room *to);
void	addlink(t_link **list, t_link *new);

//Miscellaneous

int		ft_arraylen(char **str);
int		testcase(char	*str);
void	err(void);
int		ft_list_size(t_room *stack);
int		countrooms(void);
void	printstack(t_rd **rd);
void	printrooms(t_room *roomlist);


#endif