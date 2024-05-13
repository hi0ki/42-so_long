/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:58:56 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/13 15:58:57 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	**take_textures(void **texture)
{
	texture = malloc(17 * sizeof(void *));
	texture[0] = mlx_load_png("imgs/walls/bot_cnt.png");
	texture[1] = mlx_load_png("imgs/walls/bot_left.png");
	texture[2] = mlx_load_png("imgs/walls/bot_right.png");
	texture[3] = mlx_load_png("imgs/walls/cnt_left.png");
	texture[4] = mlx_load_png("imgs/walls/cnt_right.png");
	texture[5] = mlx_load_png("imgs/walls/ground.png");
	texture[6] = mlx_load_png("imgs/walls/top_cnt.png");
	texture[7] = mlx_load_png("imgs/walls/top_left.png");
	texture[8] = mlx_load_png("imgs/walls/top_right.png");
	texture[9] = mlx_load_png("imgs/block.png");
	texture[10] = mlx_load_png("imgs/coin.png");
	texture[11] = mlx_load_png("imgs/exit.png");
	texture[12] = mlx_load_png("imgs/to_bot.png");
	texture[13] = mlx_load_png("imgs/to_left.png");
	texture[14] = mlx_load_png("imgs/to_right.png");
	texture[15] = mlx_load_png("imgs/to_top.png");
	texture[16] = NULL;
	return (texture);
}

int	check_texture(void)
{
	void	**texture;
	int		i;

	i = 0;
	texture = NULL;
	texture = take_textures(texture);
	while (i < 16)
	{
		if (texture[i] == NULL)
		{
			delete_tex(texture);
			puterror("Error: failed to load texture\n");
		}
		i++;
	}
	delete_tex(texture);
	return (0);
}
