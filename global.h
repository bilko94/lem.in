#ifndef GLOBAL_H
#define GLOBAL_H
# define START 1
# define END 2
# define RED "[0;31m"
# define GREEN "[0;32m"
# define YELLOW "[0;33m"
# define BLUE "[0;34m"
# define PURPLE "[0;35m"
# define RESET "[0m"
# include "libft/libft.h"
# include "get_next/get_next_line.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <time.h>
# define EREXIT err()

typedef struct		s_rd
{
	char			*line;
	struct s_rd		*next;
}					t_rd;

typedef struct			s_roomids
{
	int					id;
	struct s_roomids	*next;
}						t_roomids;

typedef struct			s_network
{
	int					id;
	int					visited;
	int					x;
	int					y;
	char				*name;
	struct s_network	**links;
	int					start;
	int					end;
}						t_network;

typedef struct			s_routelist
{
	int					id;
	int					ants;
	struct s_route		*route;
	struct s_routelist	*next;
}						t_routelist;

typedef struct		s_room
{
	int				id;
	int				x;
	int				y;
	int				link_count;
	char			*name;
	struct s_link	*links;
	struct s_room	*next;
	int				visited;
	int				ant;
	int				start;
	int				end;
}					t_room;

typedef struct		s_queue
{
	struct s_room	*room;
	struct s_queue	*parent;
	struct s_queue	*next;
}					t_queue;

typedef	struct		s_route
{
	struct s_room	*room;
	struct s_route	*next;
}					t_route;

typedef struct		s_link
{
	t_room			*linked_room;
	struct s_link	*next;
}					t_link;

typedef struct		s_hub
{
	t_link			*links;
	t_room			*room;
	t_network		*network;
	t_queue			*queue;
	t_routelist		*routelist;
	t_rd			*raw_data;
	int				room_count;
	int				ant_count;
	int				path_count;
}					t_hub;

// init data
int		read_in();
int		add_rd_node(t_rd **data, char *line);
int		init_build(t_hub **hub);
void	relink();
int		loop_break(int max);


// malloc
t_hub	*malloc_hub(void);
t_room	*malloc_room(void);
t_link	*malloc_link(void);
t_rd	*malloc_rd(void);
void	purge(t_hub *hub);
void	purge_t_rd(t_rd *raw_data);
void	purge_t_rooms(t_room *rooms);
void	purge_t_links(t_link *links);
void 	purge_t_queue(t_queue *queue);
void	purge_t_roomids(t_roomids *roomids);
void 	purge_t_routelist(t_routelist *routelist);
int		purge_split(int len, char **split);
void	purge_q(t_queue *queue);
t_hub	*hub(t_hub *hub);

//Algorithm stuffs
int     bfs(t_hub *hub);
int     search(t_hub *hub, t_routelist *routelist);
int	    addroomid(int id, t_roomids **roomids);
int     addroutelistnode(t_routelist **routelist, int id);
int	    addroute(t_route **route, t_room *room);
void	freeroomids(t_roomids **roomids);
void    assessqueue(t_queue **q, t_roomids *roomids, t_route **curroute);
void    addtoqueue(t_queue **q, t_queue *parent, t_room *room);
int route_len(t_route *route);

// onetap
int		onetap();
int		count_rooms(t_rd *data);
int		build_rooms(t_hub *hub);

// line instruction
int		instruction(char *line);
int ants(char *line);
int comments(char *line);
int start(char *line);
int end(char *line);
int room(char *line);
int roomlink(char *line);

// link
int		onelink();
int		link_rooms(t_hub *hub, char *line);
int		connector(t_hub *hub, t_room *room, t_room *next_room);
t_room	*find_room(t_room *roomlist, char *str);


// write
int		insert();
int		populate(t_hub *hub, t_rd *data);
int		write_room(t_room *start, char *line, int pos);
void	unvisit(t_hub *hub);

// mappers
void hub_echo(t_hub *hub);
void room_echo(t_room *room);
void mapper(t_hub *hub);
int maxvar(t_hub *hub, char mode);
int locate_room(int x, int y, t_hub *hub);
void print_links(t_link *links);
void route_echo(t_route *route);

void echo_data();
void echo_start();
void echo_end();
void echo_room();
void echo_links();
void echo_i(int ant, char *room_name);

// mover
int 	mover();
int		channel_count();
t_room	*find_room_by_id(int id);
t_route	*channel_queue(int channel, t_routelist *routelist);
void	move_channel(t_route *route);
void	ant_echo();
void	move_ant(t_route *start);
void	start_ant(t_route *start);
int		ant_present();
int		debug(int i);
void	cleanup();

#endif