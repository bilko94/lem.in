#include "../global.h"

void mover(t_hub *hub){
	int channels = channel_count(hub->routelist);
	printf("%d\n", channels);
}

int channel_count(t_routelist *route){
	int i = 0;
	t_routelist		*temp = route;
	t_route			*temproute;

    while (temp){
		temproute = temp->route;
        while (temproute){
			if (temproute->room->id == 1)
				i++;
            temproute = temproute->next;
        }
        temp = temp->next;
    }
	return (i);
}