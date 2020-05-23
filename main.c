#include "global.h"

int main(void){
	clock_t begin = clock();
	clock_t end = 0;

	debug(1);
	if (init_hub()){
		bfs(hub(0));
		echo_data();
		end = clock();
		if (debug(0))
			printf("\ninstructions:%d channels:%d execution_time:%lf sec\n",mover(), channel_count(),(double)(end - begin) / CLOCKS_PER_SEC);
	}
	purge(hub(0));
	return (0);
}
