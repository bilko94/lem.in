#include "global.h"

int main(void){
	t_hub *hub = NULL;
	
	init_build(&hub);
	printf("done !\n");
	hub_echo(hub);
	mapper(hub);
	// while(1);
	purge(hub);
	return (0);
}

