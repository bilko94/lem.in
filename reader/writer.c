#include "../global.h"

int room_writer(hub *t_hub){
	raw_map *temp = t_hub->raw_data;
	while (temp){
		if (check_ref(temp->line) == 4)
			printf("%s\n",temp->line);
		temp = temp->next;
	}
	return 0;
}
