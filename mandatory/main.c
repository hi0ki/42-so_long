/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:59:36 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/02 22:55:27 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ll()
{
		system("leaks so_long");
}

void	start(mlx *s)
{
	void *texture;

	s->mlx = mlx_init(s->width,  s->height, "so_long", 0);
	get_walls_ground(s, s->mlx);
	get_coins(s, s->mlx);
	texture = mlx_load_png("imgs/player.png");
	s->player = mlx_texture_to_image(s->mlx, texture);
	mlx_image_to_window(s->mlx, s->player, s->x, s->y);
	mlx_delete_texture(texture);
}

int	main(int ac, char **av)
{
	atexit(ll);
	int fd;
	int i;
	mlx str;

	i = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDWR);
		if (config_map(&str, fd) == 0 && check_ber(av[1]) == 0)
		{
			str.height = (arrlen(&str)) * 60;
			str.width = (ft_strlen(str.map[1])) * 60;
			if (str.width > 1920 || str.height > 1080)
				exit(0);
			start(&str);
			mlx_key_hook(str.mlx, &my_keys, &str);
			mlx_loop(str.mlx);
			mlx_delete_image(str.mlx,str.player);
			mlx_terminate(str.mlx);
			arrfree(str.map);
		}
		else
			arrfree(str.map);
	}
	return 0;
}
