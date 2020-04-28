#include "../global.h"

void hub_echo(t_hub *hub){
	printf("hub %p\t \nrooms:%d \nants:%d \npaths:%d\n", hub, hub->room_count, hub->ant_count, hub->path_count);
	t_room *temp= hub->room;
	while(temp){
		printf("%p ", temp);
		room_echo(temp);
		printf("\n");
		temp = temp->next;
	}
}

void room_echo(t_room *room){
	printf("id:%d %s", room->id, room->name);
	printf(" pos:%d %d", room->x, room->y);
	if (room->start == 1)
		printf(" start");
	else if (room->end == 1)
		printf(" end");
	else
		printf(" path");
}

void mapper(t_hub *hub){
	int currx = 0;
	int curry = 0;
	int x = maxvar(hub, 'x') + 1;
	int y = maxvar(hub, 'y') + 1;
	int room = 0;
	while (curry < y){
		while (currx < x){
			room = locate_room(currx, curry, hub);
			if (room)
				printf(" %d ", room);
			else
				printf("  ");			
			currx++;
		}
		printf("\n");
		currx = 0;
		curry++;
	}
	printf("\n");
}

int locate_room(int x, int y, t_hub *hub){
	t_room *temp = hub->room;
	while (temp){
		if (temp->x == x & temp->y == y)
			return temp->id;
		temp = temp->next;
	}
	return (0);
}

int maxvar(t_hub *hub, char mode){
	t_room *temp = hub->room;
	int max = 0;
	while (temp){
		if (mode == 'x')
			if (max < temp->x)
				max = temp->x;
		if (mode == 'y')
			if (max < temp->y)
				max = temp->y;
		temp = temp->next;
	}
	return (max);
}

void print_links(t_hub *hub){
	t_link *temp = hub->links;
	while (temp){
		printf("%d <-> %d\n", temp->room1, temp->room2);
		temp = temp->next;
	}
}