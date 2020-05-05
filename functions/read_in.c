#include "../global.h"

int		read_in(){
	char	*line;
	t_rd **data = &hub(0)->raw_data;

	while (get_next_line(0, &line)){
		if (!add_rd_node(data, line)){
			free(line);
			return (0);
		}
		line = NULL;
	}
	return (1);
}

int		add_rd_node(t_rd **data, char *line){
	t_rd	*current;
	t_rd	*new;

	new = malloc_rd();
	if (!new)
		return (0);
	new->line = line;
	current = (*data);
	if (!current)
		*data = new;
	else {
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return (1);
}

void relink(){
	t_room *start = hub(0)->room;
	t_room *temp = hub(0)->room;
	t_room *start_room = NULL;

	if (hub(0)->room->start == 1)
		return ;
	while (temp){
		if (temp->next)
			if (temp->next->start == 1){
				start_room = temp->next;
				temp->next = start_room->next;
				start_room->next = hub(0)->room;
				hub(0)->room = start_room;
				break ;
			}
		temp = temp->next;
	}
}
