#include "../global.h"

hub *constructor(){
	hub *new = reader();
	if (new == NULL)
		return NULL;
	if (build_rooms(new) == 0)
		return NULL;
	hub_debug(new);
	if (room_writer(new) == 0)
		return NULL;
	return (new);
}

void hub_debug(hub *t_hub){
	room *temp = t_hub->start_map;
	printf("hub : %p\n", t_hub);
	int i = 0;
	while(temp){
		printf("%d %p\n", i, temp);
		temp = temp->next;
		i++;
	}
}
