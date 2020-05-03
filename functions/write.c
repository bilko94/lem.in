#include "../global.h"

int insert(){
	t_rd *data = hub(0)->raw_data;
	while (data){
		if (!populate(hub(0), data))
			return (0);
		if (instruction(data->line) == 2 || instruction(data->line) == 3)
			data = data->next;
		data = data->next;
	}
	if (hub(0)->ant_count == -1)
		return (0);
	unvisit(hub(0));
	return (1);
}

int populate(t_hub *hub, t_rd *data){
	char *line = data->line;
	int ref = instruction(line);
	if (ref == 1){
		hub->ant_count = ft_atoi(line);
		return (1);
	} else if (ref == 2){
		return write_room(hub->room, data->next->line, 1);
	} else if (ref == 3){
		return write_room(hub->room, data->next->line, -1);
	} else if (ref == 5){
		return write_room(hub->room, line, 0);
	}
}

int write_room(t_room *start, char *line, int pos){
	char **str1 = NULL;

	while(start){
		if (start->visited == 0)
			break;
		start = start->next;
	}
	start->visited = 1;
	if (!(str1 = ft_strsplit(line, ' ')))
		return (1);
	start->name = str1[0];
	start->x = ft_atoi(str1[1]);
	start->y = ft_atoi(str1[2]);
	if (pos == 1)
		start->start = 1;
	else if (pos == -1)
		start->end = 1;
	free(str1[1]);
	free(str1[2]);
	free(str1);
	return (1);
}

void unvisit(t_hub *hub){
	t_room *temp = hub->room;
	while (temp){
		temp->visited = 0;
		temp = temp->next;
	}
}