#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include "depend/libft/libft.h"
#include "depend/gnl/get_next_line.h"

struct raw_map {
	char *line;
	struct raw_map *next;
}	raw_map;
struct raw_map *new_raw_map(char *c);
void echo_map(struct raw_map *raw_map_data);

struct raw_map *reader();

#endif