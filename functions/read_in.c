#include "../global.h"

int		read_in(t_rd **data){
	char	*line;

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

void relink(t_hub *hub){
	t_room *start = hub->room;
	t_room *temp = hub->room;
	t_room *start_room = NULL;

	if (hub->room->start == 1)
		return ;
	while (temp){
		if (temp->next)
			if (temp->next->start == 1){
				start_room = temp->next;
				temp->next = start_room->next;
				start_room->next = hub->room;
				hub->room = start_room;
				break ;
			}
		temp = temp->next;
	}
}
