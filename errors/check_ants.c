/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:08:23 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 15:15:15 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	check_ants(char *line)
{
	if (ft_atol(line) > INT32_MAX)
		EREXIT ;
	else if (ft_atoi(line) < 0)
		EREXIT ;
}