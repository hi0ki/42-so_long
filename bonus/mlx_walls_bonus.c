#include "so_long_bonus.h"

void	*test_walls(t_mlx *s, int x, int y)
{
	int		len_y;
	int		len_x;
	void	*texture;

	len_y = arrlen(s) - 1;
	len_x = ft_strlen(s->map[0]) - 1;
	if (y == 0 && x == 0)
		texture = mlx_load_png("imgs/walls/top_left.png");
	else if (y == 0 && x == len_x)
		texture = mlx_load_png("imgs/walls/top_right.png");
	else if (y == 0 && x > 0)
		texture = mlx_load_png("imgs/walls/top_cnt.png");
	else if (y > 0 && y == len_y && x == 0)
		texture = mlx_load_png("imgs/walls/bot_left.png");
	else if (y > 0 && y == len_y && x == len_x)
		texture = mlx_load_png("imgs/walls/bot_right.png");
	else if (y > 0 && y == len_y && x != len_x)
		texture = mlx_load_png("imgs/walls/bot_cnt.png");
	else if (y > 0 && y < len_y && x == len_x)
		texture = mlx_load_png("imgs/walls/cnt_right.png");
	else if (y > 0 && y < len_y && x == 0)
		texture = mlx_load_png("imgs/walls/cnt_left.png");
	else
		return (NULL);
	return (texture);
}

void	put_walls(t_mlx *s, int x, int y)
{
	void	*texture;
	void	*img;

	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == '1')
			{
				texture = test_walls(s, x, y);
				if (texture != NULL)
				{
					img = mlx_texture_to_image(s->mlx, texture);
					mlx_image_to_window(s->mlx, img, x * 60, y * 60);
					mlx_delete_texture(texture);
				}
			}
			x++;
		}
		y++;
	}
}

void	put_ground(t_mlx *s, int x, int y)
{
	void	*texture;
	void	*img;
	int		len_y;
	int		len_x;

	len_y = arrlen(s) - 1;
	len_x = ft_strlen(s->map[0]) - 1;
	while (s->map[y] && y < len_y)
	{
		x = 1;
		while (s->map[y][x] && x < len_x)
		{
			if (s->map[y][x] == '1')
			{
				texture = mlx_load_png("imgs/block.png");
				img = mlx_texture_to_image(s->mlx, texture);
				mlx_image_to_window(s->mlx, img, x * 60, y * 60);
				mlx_delete_texture(texture);
			}
			x++;
		}
		y++;
	}
}
