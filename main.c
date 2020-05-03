#include "global.h"

int main(void){
	t_hub *hub = NULL;
	
	if (init_build(&hub)){
		// printf("done !\n");
		// hub_echo(hub);
		// mapper(hub);
		bfs(hub);
		echo_data();
	} else {
		printf("fail ;-;\n");
	}
	purge(hub);
	return (0);
}

