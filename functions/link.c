#include "../global.h"

int onelink(t_hub *hub, t_rd *data){
	while (data){
		if (instruction(data->line) == 5)
			link_rooms(hub, data->line);
		data = data->next;
	}
}

int link_rooms(t_hub *hub, char *line){
	t_room	*to;
	t_room	*from;
	char	**str;

	str = ft_strsplit(line, '-');
	to = find_room(hub->linear, str[0]);
	from = find_room(hub->linear , str[1]);
	connector(hub, to->id, from->id);
	free(str);
}

t_room	*find_room(t_room *roomlist, char *str){
	t_room	*cursor;
	
	cursor = roomlist;
	while (cursor)
	{
		if (ft_strcmp(cursor->name, str) == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

int connector(t_hub *hub, int id1, int id2){
	t_link *temp = hub->links;
	t_link *new = malloc_link();
	new->room1 = id1;
	new->room2 = id2;
	if (!temp)
		hub->links = new;
	else {
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}


