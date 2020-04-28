/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:10:05 by solivari          #+#    #+#             */
/*   Updated: 2019/09/17 18:04:20 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

int			init_build(t_hub **hub){
	t_rd *data = NULL;

	if (((*hub) = malloc_hub())){
		if (!read_in(&(*hub)->raw_data)){
			printf("broke at read_in\n");
			return (0);
		}
		if (!onetap((*hub))){
			printf("broke at onetep\n");
			return (0);
		}
		if (!insert((*hub))){
			printf("broke at insert\n");
			return (0);
		}
		if (!onelink((*hub))){
			printf("broke at onelink\n");
			return (0);
		}
		relink(((*hub)));
		return 1;
	}
	return 0;
}

int loop_break(int max){
	static int lim = 0;
	if (max != lim)
		lim++;
	else
		return (0);
	return (1);	
}