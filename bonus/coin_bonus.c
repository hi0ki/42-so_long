/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_coin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:13:35 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/10 18:13:38 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	**get_texture(void)
{
	void	**texture;

	texture = malloc(7 * sizeof(void *));
	texture[0] = mlx_load_png("imgs/coins/coin1.png");
	texture[1] = mlx_load_png("imgs/coins/coin2.png");
	texture[2] = mlx_load_png("imgs/coins/coin3.png");
	texture[3] = mlx_load_png("imgs/coins/coin4.png");
	texture[4] = mlx_load_png("imgs/coins/coin5.png");
	texture[5] = mlx_load_png("imgs/coins/coin6.png");
	texture[6] = NULL;
	return (texture);
}

void	delete_tex(void **texture)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		mlx_delete_texture(texture[i]);
		i++;
	}
	free(texture);
	texture = NULL;
}

void	put_coins(t_mlx *s, int j)
{
	void	*img;

	img = NULL;
	if (j <= 6)
		img = mlx_texture_to_image(s->mlx, s->texture[j]); 
	mlx_image_to_window(s->mlx, img, s->c_x * 60, s->c_y * 60);
}

void	get_coins(t_mlx *s)
{
	int	x;
	int	y;

	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == 'C')
			{
				s->c_x = x;
				s->c_y = y;
				put_coins(s, s->pic);
			}
			x++;
		}
		y++;
	}
}

void	start_loop(void *param)
{
	t_mlx		*s;

	s = (t_mlx *)param;
	if (s->time > 6)
		s->time = 0;
	if (s->time == 6)
	{
		s->texture = get_texture();
		if (s->pic > 5)
			s->pic = 0;
		get_coins(s);
		delete_tex(s->texture);
		s->pic++;
	}
	s->time++;
}
