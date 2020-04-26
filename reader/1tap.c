#include "../global.h"

int build(t_hub **hub, t_rd *data){

	if (((*hub) = malloc_hub())){
		onetap((*hub), data);
		insert((*hub), data);
		return 1;
	}
	return 0;
}

int onetap(t_hub *hub, t_rd *data){
	hub->room_count = count_rooms(data);
	build_rooms(hub);
	return (0);
}

int build_rooms(t_hub *hub){
	t_room *temp = NULL;
	t_room *curr = NULL;
	int id = 0;
	int amm = hub->room_count;
	
	if ((temp = malloc_room())){
		temp->id = id + 1;
		hub->linear = temp;
		curr = hub->linear;
		amm--;
		id++;
	} else
		return (0);
	while (id <= amm){
		if ((temp = malloc_room())){
			temp->id = id + 1;
			curr->next = temp;
			curr = curr->next;
		} else
			return (0);
		id++;
	}
	return (1);
}

int		instruction(char *line){
	if (line[0] == '#' && line[1] == '#')
		return (2);
	else if (line[0] == '#' && line[1] != '#')
		return (3);
	else if (ft_wordcount(line, ' ') == 3)
		return (4);
	else if (ft_wordcount(line, '-') == 2)
		return (5);
	else if (ft_isdigit(line[0]))
		return (1);
	return (6);
}

t_hub	*malloc_hub(void){
	t_hub	*new = NULL;
	
	if ((new = (t_hub *)malloc(sizeof(t_hub)))){
		new->end = NULL;
		new->start = NULL;
		new->linear = NULL;
		new->links = NULL;
		new->room_count = 0;
		new->ant_count = 0;
		new->path_count = 0;
	}
	return (new);
}

t_room	*malloc_room(void){
	t_room	*room;
	
	if ((room = (t_room*)malloc(sizeof(t_room)))){
		room->name = NULL;
		room->start = 0;
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

int count_rooms(t_rd *data){
	int i = 0;

	while (data){
		if (instruction(data->line) == 4)
			i++;
		data = data->next;
	}
	return (i);
}

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
		check_ants(line);
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

// int link_room(){}