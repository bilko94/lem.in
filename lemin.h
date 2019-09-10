/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:17:55 by solivari          #+#    #+#             */
/*   Updated: 2019/09/10 17:21:12 by solivari         ###   ########.fr       */
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