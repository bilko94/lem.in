#include "../global.h"

int mover(t_hub *hub){
	int channels = channel_count(hub->routelist);
	int i = 0;
	int instructions= 0;
	t_room *start = find_room_by_id(1);
	start->ant = hub->ant_count;
	while (ant_present()){
		i = channels;
		while (i--)
			move_channel(channel_queue(i + 1, hub->routelist));
		if (debug(0)) printf("\n");
		instructions++;
	}
	cleanup();
	return (instructions);
}

void move_channel(t_route *route){
	if (route->next)
		if (route->next->next)
			move_channel(route->next);
	if (route->room->id == 1){
		start_ant(route);
	} else if (route->room->ant != -1){
		move_ant(route);
	}
}

int ant_present(){
	t_room *start = hub(NULL)->room;
	if (start->ant == hub(NULL)->ant_count)
		return (1);
	while (start){
		if (start->ant != -1 && start->start != 1 && start->end != 1)
			return (1);
		start = start->next;
	}
	return (0);
}

void move_ant(t_route *start){
	t_room *room = start->room;
	t_room *next = start->next->room;
	if (room && next){
		if (next->ant == -1  || next->end == 1){
			if (debug(0)) printf("L%d-%s ", room->ant, next->name);
			next->ant = room->ant;
			room->ant = -1;
		}
	}
}

void start_ant(t_route *start){
	if (start->room->ant > 0){
		if (start->next->room->ant == -1){
			start->room->ant--;
			if (debug(0)) printf("L%d-%s ", (hub(NULL)->ant_count) - (start->room->ant), start->next->room->name);
			start->next->room->ant = (hub(NULL)->ant_count) - (start->room->ant);
		}
	}
}

void ant_echo(){
	t_room *start = hub(NULL)->room;
	while (start){
		if (start->ant != -1)
			printf("room %d ant:%d\n", start->id, start->ant);
		start = start->next;
	}
}

void cleanup(){
	t_room *start = hub(NULL)->room;
	while (start){
		start->ant = -1;
		start = start->next;
	}
}

t_route *channel_queue(int channel, t_routelist *routelist){
	int channel_num = 0;
	while (routelist){
		channel_num++;
		if (channel == channel_num)
			return routelist->route;
		routelist = routelist->next;
	}
	return (NULL);
}

t_room *find_room_by_id(int id){
	t_room *temp = hub(NULL)->room;
	while (temp){
		if (temp->id == id)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int channel_count(t_routelist *route){
	int i = 0;
    while (route){
        route = route->next;
		if (route)
			i++;
    }
	return (i);
}

int debug(int i){
	static int debug_mode = 0;
	if (i == -1)
		debug_mode = 0;
	else if (i == 1)
		debug_mode = 1;
	return debug_mode;
}