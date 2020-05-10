#include "../global.h"

int mover(){
	ft_putchar('\n');
	if (channel_count()){
		int ant = 0;
		hub(0)->room->ant = hub(0)->ant_count;
		// printf("%d %s\n",hub(0)->room->ant, hub(0)->room->name);
		int i = 0;
		while (hub(0)->room->ant > 0 || present()){
			routelist_op();
			ft_putchar('\n');
			i++;
		}
	}
	// start_end(0,0,1);
	// printf("\n%d %d\n", i, hub(0)->room->ant);
}



void routelist_op(){
	t_routelist *routes = hub(0)->routelist;
	while (routes){
		route_op(routes->route);
		init_ants(routes->route);
		routes = routes->next;
	}
}
int route_op(t_route *route){
	if (route){
		route_op(route->next);
		if (route->room->ant != -1 && route->room->start != 1 && route->next){
			if (route->next->room->end == 1 || route->next->room->ant == -1){
				echo_i(route->room->ant,route->next->room->name);
				// printf("L%d-%s ", route->room->ant, route->next->room->name);
				if (route->next->room->end == 1)
					start_end(0,1,0);
				route->next->room->ant = route->room->ant;
				route->room->ant = -1;
			}
		}
	}
}

void init_ants(t_route *route){
	int ants_available = hub(0)->room->ant;
	int scheduled_ant = (hub(0)->ant_count) - (route->room->ant);
	
	int routelen = route_len(route);
	int route_short = routelen == 2 ? 1 : 0;
	int shortest_route = get_shortest_route();
	if (ants_available){
		// printf("route %p len:%d short:%d ants%d ", route, routelen, shortest_route, ants_available);
		if (routelen < hub(0)->ant_count || route_short){
			push_ants(route);
			// printf(" init\n");
		} else if (!no_valid(ants_available)){
			push_ants(route);
			// printf(" reqires alternate valid \n");
		} else {
			// printf (" queue\n");
		}
	}
}

int get_shortest_route(){
	t_routelist *routes = hub(0)->routelist;
	if (routes)
		return (route_len(routes->route));
}

int if_valid(t_route *route){
	if (route){
		if (route_len(route) <= route->room->ant * 0.5)
			return(1);
	}
	return (0);
}
int no_valid(int ant_amm){
	t_routelist *temp = hub(0)->routelist;
	while (temp->next){
		if (route_len(temp->route) <= ant_amm * 0.5)
			return (1);
		temp = temp->next;
	}
	return (0);
}
int push_ants(t_route *route){
	if (route->next->room->end == 1 || route->next->room->ant == -1){
		route->room->ant--;
		route->next->room->ant = (hub(0)->ant_count) - (route->room->ant);
		start_end(1,0,0);
		echo_i(route->next->room->ant,route->next->room->name);
		if (route->next->room->end == 1)
			start_end(0,1,0);
			
		// printf("init ant %d route:%d\n", route->next->room->ant, route_len(route));
		// printf("L%d-%s ", route->next->room->ant, route->next->room->name);
	}
}

void echoroute(){
	t_routelist *temp = hub(0)->routelist;
	while (temp){
		// printf("%p %d\n", temp->route, route_len(temp->route));
		temp = temp->next;
	}
}

void start_end(int s, int e, int p){
	static int start;
	static int end;
	if (e){
		if (!end)
			end = 1;
		else
			end++;
	} else if (s) {
		if (!start)
			start = 1;
		else
			start++;
	} else if (p) {
		printf("start : %d end : %d\n", start, end);
	}
}

int present(){
	t_room *room = hub(0)->room;
	while (room){
		if (room->end != 1 && room->start != 1 && room->ant != -1)
			return (1);
		room = room->next;
	}
	return (0);
}