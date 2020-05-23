#include "global.h"

int main(void){
	clock_t begin = clock();
	clock_t end = 0;

	if (init_hub()){
		bfs(hub(0));
		echo_data();
		end = clock();
		// printf("\n\ninstructions:%d channels:%d execution_time:%lf sec\n",mover(), channel_count(),(double)(end - begin) / CLOCKS_PER_SEC);
	} else {
		// ft_putchar('\n');
	}
	purge(hub(0));
	return (0);
}
