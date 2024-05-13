/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:49:50 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/10 18:49:51 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player(t_mlx *s, char *str, int x, int y)
{
	void	*texture;

	mlx_delete_image(s->mlx, s->player);
	texture = mlx_load_png(str);
	s->player = mlx_texture_to_image(s->mlx, texture);
	mlx_image_to_window(s->mlx, s->player, x, y);
	mlx_delete_texture(texture);
}

void	get_exit(t_mlx *s)
{
	int		x;
	int		y;
	void	*texture;
	void	*image;

	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == 'E')
			{
				texture = mlx_load_png("imgs/exit.png");
				image = mlx_texture_to_image(s->mlx, texture);
				mlx_image_to_window(s->mlx, image, x * 60, y * 60);
				mlx_delete_texture(texture);
			}
			x++;
		}
		y++;
	}
}

void	get_walls_ground(t_mlx *s, mlx_t *mlx)
{
	int		x;
	int		y;
	void	*texture;
	void	*image;

	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == '0' || s->map[y][x] == 'C' || 
				s->map[y][x] == 'P' || s->map[y][x] == 'E' || 
				s->map[y][x] == 'R')
			{
				texture = mlx_load_png("imgs/walls/ground.png");
				image = mlx_texture_to_image(mlx, texture);
				mlx_image_to_window(mlx, image, x * 60, y * 60);
				mlx_delete_texture(texture);
			}
			x++;
		}
		y++;
	}
}

void	get_enemy(t_mlx *s)
{
	int		x;
	int		y;
	void	*texture;
	void	*image;

	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == 'R')
			{
				texture = mlx_load_png("imgs/down.png");
				image = mlx_texture_to_image(s->mlx, texture);
				mlx_image_to_window(s->mlx, image, x * 60, y * 60);
				mlx_delete_texture(texture);
			}
			x++;
		}
		y++;
	}
}
