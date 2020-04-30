#include "../global.h"

int	instruction(char *line){
	if (ants(line))
		return (1);
	if (start_end(line))
		return (2);
	if (comments(line))
		return (3);
	if (room(line))
		return (4);
	if (roomlink(line))
		return (5);
	return (0);
}

int ants(char *line){
	int i = 0;
	if (ft_strlen(line) == 0)
		return (0);
	while (line[i]){
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}
int start_end(char *line){
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		return (1);
	return (0);
}
int comments(char *line){
	if (line[0] == '#' && !start_end(line))
		return (1);
	return (0);
}
int room(char *line){
	if (ft_wordcount(line, ' ') == 3)
		return (1);
	return (0);
}
int roomlink(char *line){
	if (ft_wordcount(line, '-') == 2)
		return (1);
	return (0);
}