#ifndef GLOBAL_H
#define GLOBAL_H
#include "depend/libft/libft.h"
#include "depend/get_next/get_next_line.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
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
}						t_network

typedef struct		s_room
{
	int				id;
	int				x;
	int				y;
	int				link_count;
	char			*name;
	struct s_room	**links; // = (t_room**)malloc(sizeof(t_room*) * nb of rooms + 1);
	struct s_room	*next;
	int				visited;
	int				start;
	int				end;
}					t_room;
// ex. line = 5-2
// char **connected[links] = find.room.by.name(data[1]);
// links++;

typedef struct		s_queue
{
	struct s_room	*node;
	struct s_queue	*parent;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_link
{
	t_room			*to;
	t_room			*from;
	struct s_link	*next;
}					t_link;

typedef struct		s_hub
{
	t_link			*links;
	t_room			*room;
	t_network		*network;
	t_queue			*queue;
	int				room_count;
	int				ant_count;
	int				path_count;
}					t_hub;

//Mapping

t_hub	*build_hub(t_rd **data);
void	add_data(t_hub **hub, int ref, char *line);
void	add_rd_node(t_rd **data, char *line);
void	read_data(t_hub *hub, t_rd **data);
int		check_ref(char *line);
void	read_in(t_rd **data);
void	readmap(t_rd **rd);
void	*init_hub(void);
void	start_map(void);
t_rd	*init_rd(void);
// t_rd	*create_rd_node(char *line);
// void	addnode(t_rd **rd);

//Rooms

t_room	*find_room(t_room **roomlist, char *str);
t_room	*createhead(t_room **roomlist);
t_room	*set_room(char *str);
t_room	*init_room(void);
void	add_empty_room(t_hub **hub, char *line, int identifier);
void	add_start_data(t_hub **hub, char *line);
void	add_end_data(t_hub **hub, char *line);
void	addroom(t_hub **hub, char *line);
// void	addendroom(t_hub **hub, char *line);
// void	addstartroom(t_hub **hub, char *line);

//Links

t_link	*set_link(t_room *from, t_room *to);
void	addlink(t_link **list, t_link *new);
void	room_link(t_hub *hub, char *line);

//Miscellaneous

int		ft_arraylen(char **str);
int		testcase(char	*str);
int		ft_list_size(t_room *stack);
void	printstack(t_rd **rd);
void	printrooms(t_room *roomlist);
int		countrooms(void);

//Freedom

void	free_array(char **str);

//Errors & Verification

void	check_link(t_hub **hub, char *line);
void	check_room(t_hub **hub, char *line);
void	check_line(t_hub **hub, char *line);
void	check_ants(char *line);
void	room_error(void);
void	link_error(void);
void	err(void);

// reader
struct raw_map {
	char *line;
	struct raw_map *next;
} raw_map_struct;
struct raw_map *reader();
struct raw_map *new_raw_map(char *c);
void echo_map(struct raw_map *raw_map_data);

// interpreter
struct map {
	char *name;
	int *room;
	int *links;
	int occ;
	int x;
	int y;
	struct map *next;
};

struct head {
	struct raw_map *raw_data;
	struct map *start_map;
	int start;
	int end;
	int ants;
};
struct head *interpreter(struct raw_map *raw_map_data);
struct head *head_malloc(struct raw_map *raw_data);

// instruction set
int validate_instruction_set(struct head *map_head, struct raw_map *raw_data);

#endif