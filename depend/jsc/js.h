#ifndef JS_H
#define JS_H
// #include "../global.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	registry {
	int id;
	struct registry *next;
	int vtype;
	struct array *arr;
}				registry;

typedef struct	array {
	int v;
	struct array *next;
}				array;

int			push(int id, int var);
int			pop(int id);
registry	*build_head(int vtype, int id);
registry	*find_data_head(int data_id);
array		*malloc_push(int value);
registry	*init_registry();
void		print_arr(int id);
void		end(registry *reg);
void		end_array(array *arr);
void		print_head();

#endif