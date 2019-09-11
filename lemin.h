/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:17:55 by solivari          #+#    #+#             */
/*   Updated: 2019/09/11 16:30:29 by solivari         ###   ########.fr       */
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
	t_room			**connected; // = (t_room**)malloc(sizeof(t_room*) * nb of rooms + 1);
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


#endif