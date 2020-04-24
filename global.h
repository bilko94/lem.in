#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include "depend/libft/libft.h"
#include "depend/gnl/get_next_line.h"

// reader
struct raw_map {
	char *line;
	struct raw_map *next;
} raw_map_struct;
struct raw_map *reader();
struct raw_map *new_raw_map(char *c);
void echo_map(struct raw_map *raw_map_data);

// interpreter
struct map {
	char *name;
	int *room;
	int *links;
	int occ;
	int x;
	int y;
	struct map *next;
};

struct head {
	struct raw_map *raw_data;
	struct map *start_map;
	int start;
	int end;
	int ants;
};
struct head *interpreter(struct raw_map *raw_map_data);
struct head *head_malloc(struct raw_map *raw_data);

// instruction set
int validate_instruction_set(struct head *map_head, struct raw_map *raw_data);

#endif