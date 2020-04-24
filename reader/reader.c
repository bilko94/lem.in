#include "../global.h"

struct raw_map *reader()
{
	int		i;
	char	*res;
	struct raw_map *mapData;
	struct raw_map *temp;
	struct raw_map *start;

	res = NULL;
	temp = NULL;
	start = NULL;
	mapData = NULL;
	while ((i = get_next_line(0, &res))){
		temp = new_raw_map(res);
		if (mapData == NULL){
			mapData = temp;
			start = temp;
		} else {
			mapData->next = temp;
			mapData = mapData->next;
		}
		res = NULL;
	}
	return (start);
}

struct raw_map *new_raw_map(char *c){
	struct raw_map *new = NULL;

	if ((new = (struct raw_map *)malloc(sizeof(raw_map_struct)))){
		new->line = c;
		new->next = NULL;
	}
	return (new);
}