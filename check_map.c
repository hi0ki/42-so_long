#include "so_long.h"

/*
	check walls : ✔️
	check coins	: 
	check path
	check player
	check exit
*/
int	check_walls(mlx *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s->map[i][len])
	{
		if (s->map[i][len] != '1')
			return (-1);
		len++;
	}
	while (s->map[i])
	{
		if (s->map[i][0] != '1' || s->map[i][len - 1] != '1')
			return (-1);
		i++;
	}
	len = 0;
	while (s->map[i-1][len])
	{
		if (s->map[i-1][len] != '1')
			return (-1);
		len++;
	}
	return 0;
}
