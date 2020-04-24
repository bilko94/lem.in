#include "../global.h"

hub *reader(){
	hub *new = NULL;

	if (!(new = hub_malloc()))
		return (NULL);
	if (!read_raw_data(new))
		return (purge(new));
	return new;
}

int read_raw_data(hub *new){
	int i = 0;
	char *line = NULL;
	raw_map *temp = NULL;

	while(get_next_line(0, &line)){
		if (!(temp = raw_malloc(line))){
			free(line);
			return (0);
		}
		attach_raw_data(new, temp);
		line = NULL;
	}
	return (1);
}

void attach_raw_data(hub *new, raw_map *data){
	raw_map *temp;

	temp = NULL;
	if (!new->raw_data)
		new->raw_data = data;
	else {
		temp = new->raw_data;
		while (temp->next)
			temp = temp->next;
		temp->next = data;
	}
}

void display_raw_data(hub *t_hub){
	raw_map *temp = t_hub->raw_data;
	while(temp){
		printf("%s\n",temp->line);
		temp = temp->next;
	}
}

