/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:42:51 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/10 18:42:53 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_count(t_mlx *s)
{
	void	*texture;
	void	*img;

	texture = mlx_load_png("imgs/walls/top_left.png");
	if (!texture)
		puterror("Error: Failed to load texture\n");
	img = mlx_texture_to_image(s->mlx, texture);
	if (!texture)
		puterror("Error: Failed to load texture\n");
	mlx_image_to_window(s->mlx, img, 0, 0);
	mlx_delete_texture(texture);
	texture = mlx_load_png("imgs/walls/top_cnt.png");
	if (!texture)
		puterror("Error: Failed to load texture\n");
	img = mlx_texture_to_image(s->mlx, texture);
	mlx_image_to_window(s->mlx, img, 60, 0);
	mlx_delete_texture(texture);
	s->str = ft_itoa(s->moves++);
	mlx_put_string(s->mlx, "Move:", 0, 0);
	mlx_put_string(s->mlx, s->str, 55, 0);
	free(s->str);
}

void	take_thecoins(t_mlx *s, int x, int y, char *str)
{
	void	*texture;
	void	*ground;

	if (s->map[y][x] == 'C')
	{
		s->coins -= 1;
		s->map[y][x] = '0';
		texture = mlx_load_png("imgs/walls/ground.png");
		if (!texture)
			puterror("Error: Failed to load texture\n");
		ground = mlx_texture_to_image(s->mlx, texture);
		mlx_delete_texture(texture);
		mlx_image_to_window(s->mlx, ground, x * 60, y * 60);
		mlx_delete_image(s->mlx, s->player);
		texture = mlx_load_png(str);
		if (!texture)
			puterror("Error: Failed to load texture\n");
		s->player = mlx_texture_to_image(s->mlx, texture);
		mlx_image_to_window(s->mlx, s->player, x * 60, y * 60);
		mlx_delete_texture(texture);
	}
	else if (s->map[y][x] == 'E' && s->coins == 0)
		exit(EXIT_SUCCESS);
	if (s->coins == 0)
		get_exit(s);
}

void	left_right(mlx_key_data_t keydata, t_mlx *s, int x, int y)
{
	if (keydata.key == MLX_KEY_D && keydata.action && 
		s->map[y][x + 1] != '1' && s->map[y][x + 1] != 'R')
	{
		get_count(s);
		s->player->instances->x += 60;
		get_player(s, "imgs/to_right.png", (x + 1) * 60, y * 60);
		take_thecoins(s, x + 1, y, "imgs/to_right.png");
	}
	else if (keydata.key == MLX_KEY_A && keydata.action && 
		s->map[y][x - 1] != '1' && s->map[y][x - 1] != 'R')
	{
		get_count(s);
		s->player->instances->x -= 60;
		get_player(s, "imgs/to_left.png", (x - 1) * 60, y * 60);
		take_thecoins(s, x - 1, y, "imgs/to_left.png");
	}
	if (keydata.key == MLX_KEY_D && keydata.action && s->map[y][x + 1] == 'R')
		exit(0);
	else if (keydata.key == MLX_KEY_A && keydata.action && 
		s->map[y][x - 1] == 'R')
		exit(0);
}

void	top_bot(mlx_key_data_t keydata, t_mlx *s, int x, int y)
{
	if (keydata.key == MLX_KEY_W && keydata.action && 
		s->map[y - 1][x] != '1' && s->map[y - 1][x] != 'R')
	{
		get_count(s);
		s->player->instances->y -= 60;
		get_player(s, "imgs/to_top.png", x * 60, (y - 1) * 60);
		take_thecoins(s, x, y - 1, "imgs/to_top.png");
	}
	else if (keydata.key == MLX_KEY_S && keydata.action && 
		s->map[y + 1][x] != '1' && s->map[y + 1][x] != 'R')
	{
		get_count(s);
		s->player->instances->y += 60;
		get_player(s, "imgs/to_bot.png", x * 60, (y + 1) * 60);
		take_thecoins(s, x, y + 1, "imgs/to_bot.png");
	}
	if ((keydata.key == MLX_KEY_W && keydata.action && 
			s->map[y - 1][x] == 'R') || (keydata.key == MLX_KEY_S && 
			keydata.action && s->map[y + 1][x] == 'R'))
		exit(0);
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
		exit(EXIT_FAILURE);
}
