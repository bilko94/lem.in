#include "global.h"

int main(void){
	t_hub *hub = NULL;
	clock_t begin = clock();
	clock_t end = 0;

	if (init_build(&hub)){
		bfs(hub);
		// echo_data();
		// debug(-1);
		// end = clock();
		// printf("\n\ninstructions:%d channels:%d execution_time:%lf sec\n\n",mover(), channel_count(),(double)(end - begin) / CLOCKS_PER_SEC);
		printf("debug\n");
	} else {
		printf("fail ;-;\n");
	}
	purge(hub);
	return (0);
}
