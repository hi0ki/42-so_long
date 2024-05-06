#include "so_long_bonus.h"

void get_player(mlx *s, char *str, int x, int y)
{
	void *texture;

	mlx_delete_image(s->mlx, s->player);
	texture = mlx_load_png(str);
	s->player = mlx_texture_to_image(s->mlx, texture);
	mlx_image_to_window(s->mlx, s->player, x, y);
	mlx_delete_texture(texture);
}

void get_coins(mlx *s, mlx_t *mlx)
{
	int x;
	int y;
	void *texture;
	void *img;

	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == 'C')
				texture = mlx_load_png("imgs/coin.png");
			else if (s->map[y][x] == 'E' && s->coins == 0)
				texture = mlx_load_png("imgs/exit.png");
            if (s->map[y][x] == 'C' || (s->map[y][x] == 'E' && s->coins == 0))
            {
                img = mlx_texture_to_image(mlx, texture);
			    mlx_image_to_window(mlx, img, x * 60, y * 60);
                mlx_delete_texture(texture);
            }
			x++;
		}
		y++;
	}
}
void get_walls_ground(mlx *s, mlx_t *mlx)
{
	int x;
	int y;
	void *texture;
	void *image;

	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == '0' || s->map[y][x] == 'C' || s->map[y][x] == 'P' || s->map[y][x] == 'E')
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
