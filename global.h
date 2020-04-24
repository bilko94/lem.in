#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include "depend/libft/libft.h"
#include "depend/get_next/get_next_line.h"

// reader
typedef struct	raw_map {
	char *line;
	struct raw_map *next;
}				raw_map;
// interpreter
typedef struct	room {
	char *name;
	int room;
	int *links;
	int occ;
	int x;
	int y;
	struct room *next;
}				room;
// hub
typedef struct	hub {
	struct raw_map *raw_data;
	struct room *start_map;
	int start;
	int end;
	int antamm;
	int ants;
}				hub;
// malloc
room		*room_malloc(void);
hub			*hub_malloc(void);
raw_map		*raw_malloc(char *c);
hub 		*purge(hub *t_hub);
// reader
hub 		*reader();
int			read_raw_data(hub *new);
void 		attach_raw_data(hub *new, raw_map *data);
void		display_raw_data(hub *t_hub);
// constructor
hub *constructor(void);
void hub_debug(hub *t_hub);

// build rooms
int build_rooms(hub *t_hub);
int count_rooms(raw_map *data);
void attach_rooms(hub *new, room *data);
int		check_ref(char *line);
// writer
int room_writer(hub *t_hub);

#endif