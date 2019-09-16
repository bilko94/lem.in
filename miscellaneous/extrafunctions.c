/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrafunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:43:01 by solivari          #+#    #+#             */
/*   Updated: 2019/09/16 16:37:38 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	printstack(t_rd **rd)
{
	t_rd	*cursor;

	cursor = (*rd);
	while (cursor->next)
	{
		printf("\t\t%s\n", cursor->line);
		cursor = cursor->next;
	}
}
