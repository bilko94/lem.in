#include "../global.h"

int	instruction(char *line){
	if (line[0] == '#' && line[1] == '#')
		return (2);
	else if (line[0] == '#' && line[1] != '#')
		return (3);
	else if (ft_wordcount(line, ' ') == 3)
		return (4);
	else if (ft_wordcount(line, '-') == 2)
		return (5);
	else if (ft_isdigit(line[0]))
		return (1);
	return (6);
}