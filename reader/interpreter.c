#include "../global.h"

struct head *interpreter(struct raw_map *raw_map_data){
	struct raw_map *begin = raw_map_data;
	int instruction = 0;
	struct head *head= head_malloc(raw_map_data);
	while (begin){
		printf("%s IS-> %d\n", begin->line, validate_instruction_set(head, begin));
		instruction = validate_instruction_set(head, begin);
		begin = begin->next;
	}
	return NULL;
}

struct head *head_malloc(struct raw_map *raw_data){
	struct head *new = NULL;

	if ((new = (struct head *)malloc(sizeof(struct head)))){
		new->raw_data = raw_data;
		new->start_map = NULL;
		new->start = -1;
		new->end = -1;
		new->ants = 0;
	}
	return (new);
}