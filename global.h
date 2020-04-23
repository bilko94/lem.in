#ifndef GLOBAL_H
# define GLOBAL_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "dependencies/libft/libft.h"
# include "dependencies/get_next_line/get_next_line.h"

struct raw_map {
	char *line;
	struct rawmap *next;
} raw_map;
raw_map *raw_map_malloc(char *c)

int reader();

#endif