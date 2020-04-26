/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:28:12 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 18:01:44 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

void	err(void)
{
	ft_putendl_fd(RED "Error, non-compliant or empty line\n" RESET, 2);
	exit(1);
}

void	check_line(t_hub *hub, char *line)
{
	if (!line)
		err();
	if (line == NULL)
		err();
}