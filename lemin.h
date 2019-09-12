/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:17:55 by solivari          #+#    #+#             */
/*   Updated: 2019/09/12 15:26:48 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# define EREXIT err()

typedef struct		s_rd
{
	void			*name;
	int				x;
	int				y;
	int				dx;
	char			*line;
	struct s_rd		*next;
	struct s_rd		*prev;
}					t_rd;

typedef struct		s_room
{
	int				x;
	int				y;
	int				start;
	int				end;
	char			*name;
	int				links;
	struct s_room	**connected; // = (t_room**)malloc(sizeof(t_room*) * nb of rooms + 1);
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;
// ex. line = 5-2
// char **connected[links] = find.room.by.name(data[1]);
// links++;

typedef struct		s_bd
{
	void			*name;
	int				x;
	int				y;
	int				dx;
	char			*line;
	struct s_bd		*next;
	struct s_bd		*prev;
}					t_bd;

// t_room	*startroom(char *str);
t_rd	*create_node(char *line);
void	addnode(t_rd **rd, char *line);
void	readmap(t_rd **rd);
t_rd	*initialize(t_rd **rd);
void	checkmap(void);
void	addlink(t_room **roomlist, char **str);
t_room	*findroom(t_room **roomlist, char *str);
t_room	*room(char *str);
void	addendroom(t_room **roomlist, char *line);
void	addstartroom(t_room **roomlist, char *line);
void	addroom(t_room **roomlist, char *line);
t_room	*initializeroom(void);
// void	createroom(char **str);
int		ft_arraylen(char **str);
int		testcase(char	*str);
void	err(void);
t_room	*createhead(t_room **roomlist);
void	map(t_rd **rd, t_room **roomlist);
int		ft_list_size(t_room *stack);
void	printstack(t_rd **rd);


#endif