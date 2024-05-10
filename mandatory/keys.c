/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:13:07 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/06 15:13:09 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_thecoins(t_mlx *s, int x, int y, char *str)
{
	void	*texture;
	void	*ground;

	if (s->map[y][x] == 'C')
	{
		s->coins -= 1;
		s->map[y][x] = '0';
		texture = mlx_load_png("imgs/walls/ground.png");
		ground = mlx_texture_to_image(s->mlx, texture);
		mlx_delete_texture(texture);
		mlx_image_to_window(s->mlx, ground, x * 60, y * 60);
		mlx_delete_image(s->mlx, s->player);
		texture = mlx_load_png(str);
		s->player = mlx_texture_to_image(s->mlx, texture);
		mlx_image_to_window(s->mlx, s->player, x * 60, y * 60);
		mlx_delete_texture(texture);
	}
	else if (s->map[y][x] == 'E' && s->coins == 0)
		exit(EXIT_SUCCESS);
	if (s->coins == 0)
		get_coins(s, s->mlx);
}

void	left_right(mlx_key_data_t keydata, t_mlx *s, int x, int y)
{
	if (keydata.key == MLX_KEY_D && keydata.action && s->map[y][x + 1] != '1')
	{
		mini_putnbr(s->moves++);
		write(1, "\n", 1);
		s->player->instances->x += 60;
		get_player(s, "imgs/to_right.png", (x + 1) * 60, y * 60);
		take_thecoins(s, x + 1, y, "imgs/to_right.png");
	}
	else if (keydata.key == MLX_KEY_A && keydata.action && 
		s->map[y][x - 1] != '1')
	{
		mini_putnbr(s->moves++);
		write(1, "\n", 1);
		s->player->instances->x -= 60;
		get_player(s, "imgs/to_left.png", (x - 1) * 60, y * 60);
		take_thecoins(s, x - 1, y, "imgs/to_left.png");
	}
}

void	top_bot(mlx_key_data_t keydata, t_mlx *s, int x, int y)
{
	if (keydata.key == MLX_KEY_W && keydata.action && s->map[y - 1][x] != '1')
	{
		mini_putnbr(s->moves++);
		write(1, "\n", 1);
		s->player->instances->y -= 60;
		get_player(s, "imgs/to_top.png", x * 60, (y - 1) * 60);
		take_thecoins(s, x, y - 1, "imgs/to_top.png");
	}
	else if (keydata.key == MLX_KEY_S && keydata.action && 
		s->map[y + 1][x] != '1')
	{
		mini_putnbr(s->moves++);
		write(1, "\n", 1);
		s->player->instances->y += 60;
		get_player(s, "imgs/to_bot.png", x * 60, (y + 1) * 60);
		take_thecoins(s, x, y + 1, "imgs/to_bot.png");
	}
}

void	my_keys(mlx_key_data_t keydata, void *param)
{
	t_mlx	*s;
	int		x;
	int		y;

	s = (t_mlx *)param;
	x = s->player->instances->x / 60;
	y = s->player->instances->y / 60;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		top_bot(keydata, s, x, y);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_A)
		left_right(keydata, s, x, y);
	else if (keydata.key == MLX_KEY_ESCAPE)
		exit(1);
}
