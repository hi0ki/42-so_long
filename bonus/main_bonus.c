/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:59:36 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/04 10:58:36 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	start(t_mlx *s)
{
	s->mlx = mlx_init(s->width, s->height, "so_long", 0);
	get_walls_ground(s, s->mlx);
	put_walls(s, 0, 0);
	put_ground(s, 1, 1);
	s->time = 0;
	s->pic = 0;
	get_enemy(s);
	mlx_loop_hook(s->mlx, start_loop, s);
	get_player(s, "imgs/to_bot.png", s->x, s->y);
}

int	main(int ac, char **av)
{
	int		fd;
	t_mlx	str;

	if (ac == 2)
	{
		fd = open(av[1], O_RDWR);
		if (fd == -1 || check_texture() != 0)
			puterror("Error: Invalid file\n");
		if (config_map(&str, fd) == 0 && check_ber(av[1]) == 0)
		{
			str.height = (arrlen(&str)) * 60;
			str.width = (ft_strlen(str.map[1])) * 60;
			if (str.width > 2080 || str.height > 1920)
				puterror("Error: The width or height is too high\n");
			start(&str);
			str.moves = 1;
			mlx_key_hook(str.mlx, &my_keys, &str);
			mlx_loop(str.mlx);
			mlx_delete_image(str.mlx, str.player);
			mlx_terminate(str.mlx);
			arrfree(str.map);
		}
	}
	else
		puterror("Error\n");
}
