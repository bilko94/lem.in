#include "global.h"

int main(void){
	t_hub *hub = NULL;
	
	if (init_build(&hub)){
		printf("done !\n");
		hub_echo(hub);
		mapper(hub);
		bfs(hub);
	} else {
		printf("fail ;-;\n");
	}
	purge(hub);
	// while(1);
	return (0);
}

