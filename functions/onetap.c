#include "../global.h"

int onetap(t_hub *hub){
	hub->room_count = count_rooms(hub->raw_data);
	if (hub->room_count)
		return build_rooms(hub);
	return (0);
}

int count_rooms(t_rd *data){
	int i = 0;

	while (data){
		if (instruction(data->line) == 5)
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
		hub->room = temp;
		curr = hub->room;
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
