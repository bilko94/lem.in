#include "global.h"

int main(void){
	struct raw_map *raw_map_data;

	raw_map_data = reader();
	echo_map(raw_map_data);
	return (0);
}

void echo_map(struct raw_map *raw_map_data){
	int i = 0;
	printf("\n##################\nraw map data ->\n\n");
	while(raw_map_data){
		printf("%s\n", raw_map_data->line);
		raw_map_data = raw_map_data->next;
		i++;
	}
	printf("##################\n");
}