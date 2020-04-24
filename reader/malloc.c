#include "../global.h"

room *room_malloc(void){
	room *new = NULL;

	if ((new = (room *)malloc(sizeof(room)))){
		new->name = NULL;
		new->room = 0;
		new->links = NULL;
		new->occ = 0;
		new->x = 0;
		new->y = 0;
		new->next = NULL;
	}
	return (new);
}

raw_map *raw_malloc(char *c){
	raw_map *new = NULL;

	if ((new = (raw_map *)malloc(sizeof(raw_map)))){
		new->line = c;
		new->next = NULL;
	}
	return (new);
}

hub *hub_malloc(void){
	hub *new = NULL;

	if ((new = (hub *)malloc(sizeof(hub)))){
		new->raw_data = NULL;
		new->start_map = NULL;
		new->start = -1;
		new->end = -1;
		new->ants = 0;
		new->antamm = 0;
	}
	return (new);
}

hub *purge(hub *t_hub){
	return NULL;
}
