/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:34:28 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 18:01:59 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

int		testcase(char	*str)
{
	if (ft_strcmp(str, "") == 0)
		return (1);
	return (0);
}