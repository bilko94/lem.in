#include "../global.h"

int	reader()
{
	char	*res;
	raw_map *how;
	int		i;

	res = "";
	i = 0;
	while ((i = get_next_line(0, &res)))
	{
		how = raw_map_malloc(res);
		printf("%s\n", how->line);
		res = "";
	}
	return (1);
}

raw_map *raw_map_malloc(char *c){
	raw_map *new = NULL;

	if (!(new = malloc(sizeof(raw_map))))
		return NULL;
	new->line = c;
	new->next = NULL;
	return (new);
}