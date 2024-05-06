#include "so_long.h"

void 	find_player(mlx *s)
{
	int	y;
	int	x;

	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == 'P')
			{
                s->x = x * 60;
                s->y = y * 60;
                return ;
            }
			x++;
		}
		y++;
	}
}

int more_check(mlx *s)
{
    char	**arr;
	int		coins;

    arr = NULL;
	coins = check_coins_e(s);
	arr = copy_arr(s);
    find_player(s);
	check_path(arr, s->x / 60, s->y / 60, s);
	arrfree(arr);
	if (coins == s->coins && s->exit == 1)
		return (0);
    else
		return (-1);
}
int	config_map(mlx *s, int fd)
{
	char	*tmp;
	char	*str;

	str = NULL;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	while (tmp)
	{
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
    }
	s->map = ft_split(str, '\n');
	free(str);
	if (check_walls(s) == -1 || check_coins_e(s) == 0 || check_player(s) == -1 || more_check(s) == -1)
	{
		return (-1);
	}
	return (0);
}