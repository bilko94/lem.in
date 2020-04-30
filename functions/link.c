#include "../global.h"

int onelink(t_hub *hub){
	t_rd *data = hub->raw_data;

	while (data){
		if (instruction(data->line) == 6)
			if (!link_rooms(hub, data->line))
				return (0);
		data = data->next;
	}
	return (1);
}

int link_rooms(t_hub *hub, char *line){
	t_room	*to;
	t_room	*from;
	char	**str;
	if (!(str = ft_strsplit(line, '-')))
		return (0);
	if (!(to = find_room(hub->room, str[0])))
		return (purge_split(2, str));
	if (!(from = find_room(hub->room, str[1])))
		return (purge_split(2, str));
	if (!connector(hub, to, from))
		return (purge_split(2, str));
	purge_split(2, str);
	return (1);
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

int connector(t_hub *hub, t_room *room, t_room *next_room){
	t_link *new = malloc_link();
	if (!new)
		return (0);
	t_link *temp = room->links;
	new->linked_room = next_room;
	if (!temp){
		room->links = new;
	} else {
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}
