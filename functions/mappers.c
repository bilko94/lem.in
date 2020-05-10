#include "../global.h"

void hub_echo(t_hub *hub){
	printf("hub %p\t \nrooms:%d \nants:%d \npaths:%d\n", hub, hub->room_count, hub->ant_count, hub->path_count);
	t_room *temp= hub->room;
	while(temp){
		printf("%p ", temp);
		room_echo(temp);
		print_links(temp->links);
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

void print_links(t_link *links){
	t_link *temp = links;
	printf(" links <->");
	while (temp){
		printf(" %d:%p",  temp->linked_room->id, temp->linked_room);
		temp = temp->next;
	}
}

void route_echo(t_route *route){
    while (route){
        printf("route goes: %d\n",route->room->id);
	    route = route->next;
    }
}

void echo_data(){
	// ft_putnbr(hub(0)->ant_count);
	// ft_putchar('\n');
	// echo_start();
	// echo_end();
	// echo_room();
	// echo_links();
	// // debug(1);
	// ft_putchar('\n');
	t_rd *raw_data = hub(0)->raw_data;
	while (raw_data){
		ft_putstr(raw_data->line);
		ft_putchar('\n');
		raw_data = raw_data->next;
	}
	mover();
}

void echo_start(){
	t_rd *raw_data = hub(0)->raw_data;
	while (raw_data){
		if (instruction(raw_data->line) == 2){
			ft_putstr(raw_data->line);
			ft_putchar('\n');
			ft_putstr(raw_data->next->line);
			ft_putchar('\n');
			return ;
		}
		raw_data = raw_data->next;
	}
}

void echo_end(){
	t_rd *raw_data = hub(0)->raw_data;
	while (raw_data){
		if (instruction(raw_data->line) == 3){
			ft_putstr(raw_data->line);
			ft_putchar('\n');
			ft_putstr(raw_data->next->line);
			ft_putchar('\n');
			return ;
		}
		raw_data = raw_data->next;
	}
}

void echo_room(){
	t_rd *raw_data = hub(0)->raw_data;
	while (raw_data){
		if (instruction(raw_data->line) == 5){
			ft_putstr(raw_data->line);
			ft_putchar('\n');
		}
		raw_data = raw_data->next;
	}
}

void echo_links(){
	t_rd *raw_data = hub(0)->raw_data;
	while (raw_data){
		if (instruction(raw_data->line) == 6){
			ft_putstr(raw_data->line);
			ft_putchar('\n');
		}
		raw_data = raw_data->next;
	}
}

void echo_i(int ant, char *room_name){
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room_name);
	ft_putchar(' ');
}
