#include "../global.h"

int build_rooms(hub *t_hub){
	int room_amm = count_rooms(t_hub->raw_data);
	room *temp = NULL;

	while(room_amm--){
		if (!(temp = room_malloc())){
			return (0);
		}
		attach_rooms(t_hub, temp);
		temp = NULL;
	}
	return (1);
}

void attach_rooms(hub *new, room *data){
	room *temp;

	temp = NULL;
	if (!new->start_map)
		new->start_map = data;
	else {
		temp = new->start_map;
		while (temp->next)
			temp = temp->next;
		temp->next = data;
	}
}

int count_rooms(raw_map *data){
	int i = 0;

	while(data){
		if (check_ref(data->line) == 4)
			i++;
		data = data->next;
	}
	return i;
}

int		check_ref(char *line){
	// if (ft_isdigit(line))
	// 	return (1);
	// else
	if (line[0] == '#' && line[1] == '#')
		return (2);
	else if (line[0] == '#' && line[1] != '#')
		return (3);
	else if (ft_wordcount(line, ' ') == 3)
		return (4);
	else if (ft_wordcount(line, '-') == 2)
		return (5);
	return (6);
}
