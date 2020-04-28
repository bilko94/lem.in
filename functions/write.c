#include "../global.h"

int insert(t_hub *hub, t_rd *data){
	while (data){
		if (!populate(hub, data))
			return (0);
		if (instruction(data->line) == 2)
			data = data->next;
		data = data->next;
	}
}

int populate(t_hub *hub, t_rd *data){
	char *line = data->line;
	int ref = instruction(line);
	if (ref == 1){
		hub->ant_count = ft_atoi(line);
	} else if (ref == 2) {
		if (ft_strcmp(line, "##start") == 0)
			return write_room(hub->linear, data->next->line, 1);
		else if (ft_strcmp(line, "##end") == 0)
			return write_room(hub->linear, data->next->line, -1);
	} else if (ref == 4){
		return write_room(hub->linear, line, 0);
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
	str1 = ft_strsplit(line, ' ');
	start->name = str1[0];
	start->x = ft_atoi(str1[1]);
	start->y = ft_atoi(str1[2]);
	if (pos == 1)
		start->start = 1;
	else if (pos == -1)
		start->end = 1;
	free(str1);
	return (1);
}