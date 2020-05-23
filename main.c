#include "global.h"

int main(void){
	performance_meter('b');

	if (init_hub()){
		bfs(hub(0));
		echo_data();
		performance_meter('d');
	}
	purge(hub(0));
	return (0);
}
