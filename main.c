/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:59:36 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/04/29 15:10:54 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_keyfunc key_func()
{
	
}

void	start(mlx *s)
{
	void *mlx;
	void *test;
	void *img;

	mlx = mlx_init(s->y * 60,  s->x * 60, "mehdi", 0);
	test = mlx_load_png("test.png");
	img = mlx_texture_to_image(mlx, test);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, key_func(), s);
	mlx_loop(mlx);
}

int	config_map(mlx *s, int fd)
{
	char	*tmp;
	char	*str;
	char	**arr = NULL;
	int		coins;

	str = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	s->map = ft_split(str, '\n');
	free(str);
	if (check_walls(s) == -1 && check_coins_e(s) == 0 && check_player(s) == -1)
		return (-1);
	coins = check_coins_e(s);
	arr = copy_arr(s);
	check_path(arr, 1, 1, s);
	arrfree(arr);
	if (coins == s->coins && s->exit == 1)
		return (0);
	else
		return (-1);
}

int	main(int ac, char **av)
{
	int fd;
	int i;
	mlx str;

	i = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDWR);
		if (config_map(&str, fd) == 0)
			printf("done\n");
		str.x = arrlen(&str);
		str.y = ft_strlen(str.map[1]);
		start(&str);
		arrfree(str.map);
	}
	system("leaks so_long");
	return 0;
}
