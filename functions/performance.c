#include "../global.h"

int debug(int i){
	static int debug_mode = 0;
	if (i == -1)
		debug_mode = 0;
	else if (i == 1)
		debug_mode = 1;
	return debug_mode;
}

void performance_meter(char in_type){
    clock_t in = clock();
    static clock_t begin_static = 0;
    static clock_t read_data_static = 0;
    static clock_t algo_done_static = 0;
    static clock_t move_done_static = 0;
    // (double)(end - begin_static) / CLOCKS_PER_SEC
    if (in_type == 'b') begin_static = in;
    else if (in_type == 'r') read_data_static = in;
    else if (in_type == 'a') algo_done_static = in;
    else if (in_type == 'm') move_done_static = in;
    else if (in_type == 'd'){
        debug(1);
        double t_read = (double)(read_data_static - begin_static) / CLOCKS_PER_SEC;
        double t_algo = (double)(algo_done_static - begin_static) / CLOCKS_PER_SEC;
        double t_move = (double)(move_done_static - begin_static) / CLOCKS_PER_SEC;
        double t_done = (double)(in - begin_static) / CLOCKS_PER_SEC;
        printf("\ninstructions:%d channels:%d \n",mover(), channel_count());
        printf("\nread %lf\tdelta t : %lf ms", t_read, t_read);
        printf("\nalgo %lf\tdelta t : %lf ms", t_algo, t_algo - t_read);
        printf("\nmove %lf\tdelta t : %lf ms\nmove (no insctruction echo) delta t :%lf", t_move, t_move - t_algo, move_noprint());
        printf("\ntotal execution time: %lf\n", t_done);
    }
}

double move_noprint(){
    clock_t begin = clock();
    mover();
    clock_t end = clock();
    return ((double)end - (double)begin);
}