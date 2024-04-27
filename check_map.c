#include "so_long.h"

/*
	check walls
	check coins
	check path
	check player
	check exit
*/
void puterror(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
void	check_walls(mlx *s)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (s->map[i][len])
	{
		if (s->map[i][len] != '1')
			puterror();
		len++;
	}
	while (s->map[i])
	{
		if (s->map[i][0] != '1' || s->map[i][len - 1] != '1')
			puterror();
		i++;
	}
	while (s->map[i-1][j])
	{
		if (s->map[i-1][j] != '1')
			puterror();
		j++;
	}
	printf("success makynch 0\n");
}
