#include "../global.h"

int onetap(t_hub *hub, t_rd *data){
	hub->room_count = count_rooms(data);
	build_rooms(hub);
	return (0);
}

int count_rooms(t_rd *data){
	int i = 0;

	while (data){
		if (instruction(data->line) == 4)
			i++;
		data = data->next;
	}
	return (i);
}

int build_rooms(t_hub *hub){
	t_room *temp = NULL;
	t_room *curr = NULL;
	int id = 0;
	int amm = hub->room_count;
	
	if ((temp = malloc_room())){
		temp->id = id + 1;
		hub->linear = temp;
		curr = hub->linear;
		amm--;
		id++;
	} else
		return (0);
	while (id <= amm){
		if ((temp = malloc_room())){
			temp->id = id + 1;
			curr->next = temp;
			curr = curr->next;
		} else
			return (0);
		id++;
	}
	return (1);
}

int	instruction(char *line){
	if (line[0] == '#' && line[1] == '#')
		return (2);
	else if (line[0] == '#' && line[1] != '#')
		return (3);
	else if (ft_wordcount(line, ' ') == 3)
		return (4);
	else if (ft_wordcount(line, '-') == 2)
		return (5);
	else if (ft_isdigit(line[0]))
		return (1);
	return (6);
}