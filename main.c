#include "so_long.h"

void config_map(mlx *s,int fd)
{
	char	*tmp;
	char	*str;

	str = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		str = ft_strjoin(str, tmp);
		tmp = get_next_line(fd);
	}
	s->map = ft_split(str, '\n');
	check_walls(s);
}
int	main(int ac, char **av)
{
	int fd;
	mlx str;
	(void)ac;
	fd = open(av[1], O_RDWR);
	config_map(&str, fd);
	return 0;
}
