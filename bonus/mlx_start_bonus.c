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

void my_coin(void *param)
{
	t_mlx *s;
	void *texture;


	s = (t_mlx *)param;
	if (s->enb_img == false)
		return ;
	s->time += 1;
	if (s->time == 30)
		s->time = 10;
	if (s->time == 10)
	{
		mlx_delete_image(s->mlx, s->img);
		texture = mlx_load_png("imgs/Money1.png");
		s->img = mlx_texture_to_image(s->mlx, texture);
		mlx_image_to_window(s->mlx, s->img, s->c_x * 60, s->c_y * 60);
		mlx_delete_texture(texture);
	}
	else if (s->time == 20)
	{
		mlx_delete_image(s->mlx, s->img);
		texture = mlx_load_png("imgs/Money2.png");
		s->img = mlx_texture_to_image(s->mlx, texture);
		mlx_image_to_window(s->mlx, s->img, s->c_x * 60, s->c_y * 60);
		mlx_delete_texture(texture);
	}
	else if (s->time == 30)
	{
		mlx_delete_image(s->mlx, s->img);
		texture = mlx_load_png("imgs/Money3.png");
		s->img = mlx_texture_to_image(s->mlx, texture);
		mlx_image_to_window(s->mlx, s->img, s->c_x * 60, s->c_y * 60);
		mlx_delete_texture(texture);
	}
}

void	get_coins(t_mlx *s, mlx_t *mlx)
{
	int		x;
	int		y;

	y = 0;
	s->time = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == 'C')
			{
				s->c_x = x;
				s->c_y = y;
				s->enb_img = true;
				printf("%d, %d\n", s->c_x, s->c_y);
				mlx_loop_hook(mlx, my_coin, s);
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
				s->map[y][x] == 'P' || s->map[y][x] == 'E')
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