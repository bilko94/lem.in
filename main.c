#include "global.h"

void hub_echo(t_hub *hub);
void room_echo(t_room *room);
void mapper(int x, int y, t_hub *hub);
int locate_room(int x, int y, t_hub *hub);

int main(void){
	t_rd *test1 = NULL;
	t_hub *hub = NULL;

	read_in(&test1);
	build(&hub, test1);
	printf("done !\n");
	hub_echo(hub);
	mapper(24, 11, hub);
	return (0);
}

void hub_echo(t_hub *hub){
	printf("hub %p\t \nrooms:%d \nants:%d \npaths:%d\n", hub, hub->room_count, hub->ant_count, hub->path_count);
	t_room *temp= hub->linear;
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

void mapper(int x, int y, t_hub *hub){
	int currx = 0;
	int curry = 0;
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
}

int locate_room(int x, int y, t_hub *hub){
	t_room *temp = hub->linear;
	while (temp){
		if (temp->x == x & temp->y == y)
			return temp->id;
		temp = temp->next;
	}
	return (0);
}