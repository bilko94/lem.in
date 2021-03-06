#include "../global.h"

t_hub	*malloc_hub(void){
	t_hub	*new = NULL;
	
	if ((new = (t_hub *)malloc(sizeof(t_hub)))){
		new->network = NULL;
		new->room = NULL;
		new->links = NULL;
		new->routelist = NULL;
		new->queue = NULL;
		new->room_count = 0;
		new->ant_count = -1;
		new->path_count = 0;
	}
	hub(new);
	return (new);
}

t_room	*malloc_room(void){
	t_room	*room;
	
	if ((room = (t_room*)malloc(sizeof(t_room)))){
		room->name = NULL;
		room->id = 0;
		room->start = 0;
		room->ant = -1;
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
		new->linked_room = NULL;
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

t_hub *hub(t_hub *hub){
	static t_hub *int_hub;
	if (hub)
		int_hub = hub;
	return (int_hub);
};

void purge(t_hub *hub){
	if (hub){
		if (hub->raw_data)
			purge_t_rd(hub->raw_data);
		if (hub->room)
			purge_t_rooms(hub->room);
		if (hub->routelist)
			purge_t_routelist(hub->routelist);
		if (hub->queue){
			// printf("hub->queue still exists\n");
			purge_t_queue(hub->queue);
		}
		// printf("links: %d\n", hub->links? 1:0);
		// printf("room: %d\n", hub->room? 1:0);
		// printf("network: %d\n", hub->network? 1:0);
		// printf("queue: %d\n", hub->queue? 1:0);
		// printf("routelist: %d\n", hub->routelist? 1:0);
		// printf("raw_data: %d\n", hub->raw_data? 1:0);
		free(hub);
	}
}

void purge_t_roomids(t_roomids *roomids){
	// printf("purging routelist\n");
	t_roomids *temp = roomids;
	t_roomids *next = NULL;
	while (temp){
		next = temp->next;
		free(temp);
		temp = next;
	}
}

void purge_t_queue(t_queue *queue){
	// printf("purging routelist\n");
	t_queue *temp = queue;
	t_queue *next = NULL;
	while (temp){
		next = temp->next;
		free(temp);
		temp = next;
	}
}

void purge_t_routelist(t_routelist *routelist){
	t_routelist *temp = routelist;
	t_route		*tmp = NULL;
	t_route		*tmpnext = NULL;
	t_routelist *next = NULL;
	while (temp){
		next = temp->next;
		tmp = temp->route;
		while (tmp){
			tmpnext = tmp->next;
			free(tmp);
			tmp = tmpnext;
		}
		free(temp);
		temp = next;
	}
}

void purge_t_rd(t_rd *raw_data){
	// printf("purging rd's\n");
	t_rd *temp = raw_data;
	t_rd *next = NULL;
	while (temp){
		next = temp->next;
		free(temp->line);
		free(temp);
		temp = next;
	}
}

void purge_t_rooms(t_room *rooms){
	t_room *temp = rooms;
	t_room *next = NULL;
	while (temp){
		next = temp->next;
		free(temp->name);
		purge_t_links(temp->links);
		free(temp);
		temp = next;
	}
}

void purge_t_links(t_link *links){
	t_link *temp = links;
	t_link *next = NULL;
	while (temp){
		next = temp->next;
		free(temp);
		temp = next;
	}
}

int purge_split(int len, char **split){
	while (len--)
		free(split[len]);
	free(split);
	return (0);
}