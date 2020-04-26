#include "global.h"



// extern registry *reg;

int main(void){
	t_rd *test1 = NULL;
	t_hub *hub = NULL;
	
	// init_registry();
	read_in(&test1);
	init_build(&hub, test1);
	printf("done !\n");
	hub_echo(hub);
	print_links(hub);
	mapper(hub);
	return (0);
}

