/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:59:36 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/01 19:47:36 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	}
	system("leaks so_long");
	return 0;
}
