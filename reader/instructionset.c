#include "../global.h"

int validate_instruction_set(struct head *map_head, struct raw_map *raw_data){
	// if (ft_isdigit(line[0]))
		// return (1);
	// else 
	char *line = raw_data->line;
	if (line[0] == '#' && line[1] == '#')
		return (2);// start/end
	else if (line[0] == '#' && line[1] != '#')
		return (3);// comments
	else if (ft_wordcount(line, ' ') == 3)
		return (4);// rooms
	else if (ft_wordcount(line, '-') == 2)
		return (5);// links
	return (6);
}

// void set_ants(){}
