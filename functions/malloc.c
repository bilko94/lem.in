#include "../global.h"

t_hub	*malloc_hub(void){
	t_hub	*new = NULL;
	
	if ((new = (t_hub *)malloc(sizeof(t_hub)))){
		// new->end = NULL;
		// new->start = NULL;
		new->network = NULL;
		new->room = NULL;
		new->links = NULL;
		new->room_count = 0;
		new->ant_count = 0;
		new->path_count = 0;
	}
	return (new);
}

t_room	*malloc_room(void){
	t_room	*room;
	
	if ((room = (t_room*)malloc(sizeof(t_room)))){
		room->name = NULL;
		room->start = 0;
		room->end = 0;
		room->x = 0;
		room->y = 0;
		room->link_count = 0;
		room->visited = 0;
		room->links = NULL;
		room->next = NULL;
	}
	return (room);
}

t_link	*malloc_link(void){
	t_link	*new = NULL;
	
	if ((new = (t_link *)malloc(sizeof(t_link)))){
		new->room1 = -1;
		new->room2 = -1;
		new->next = NULL;
	}
	return (new);
}

t_rd	*malloc_rd(void){
	t_rd	*new;

	if (!(new = (t_rd *)malloc(sizeof(t_rd))))
		return (false);
	new->line = NULL;
	new->next = NULL;
	return (new);
}