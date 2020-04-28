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
	to = find_room(hub->room, str[0]);
	from = find_room(hub->room, str[1]);
	connector(hub, to, from);
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

int connector(t_hub *hub, t_room *room, t_room *next_room){
	t_link *new = malloc_link();
	t_link *temp = room->links;
	new->linked_room = next_room;
	// printf("####### connecting ########\n");
	// printf("binding %s:%p to %d:%p\n", room->name, room, next_room->id, next_room);
	if (!temp){
		// printf("first node:%p attaching %d:%p to links of %d\n", new,new->linked_room->id, new->linked_room, room->id);
		room->links = new;
	}
	else {
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		// printf("secon node:%p attaching %d:%p to links of %d\n", new,new->linked_room->id, new->linked_room, room->id);
	}
	// printf("%s's", room->name);
	// print_links(room->links);
	// printf("\n####### connected #########\n\n\n");
	return (1);
}
