#include "../global.h"

void mover(t_hub *hub){
	int channels = channel_count(hub->routelist);
	t_routelist *temp = hub->routelist;
	printf("%p\n", temp);
    while (temp){
		printf("%p\n", temp->route);
        while (temp->route){
            printf("route goes: %d\n", temp->route->room->id);
            temp->route = temp->route->next;
        }
        temp = temp->next;
    }
	printf("%d\n", channels);
}

int channel_count(t_routelist *route){
	int i = 0;
	// t_routelist *temp = route;
    // while (temp){
    //     while (temp->route){
    //         printf("route goes: %d\n", temp->route->room->id);
    //         temp->route = temp->route->next;
    //     }
    //     temp = temp->next;
    // }
	return (i);
}