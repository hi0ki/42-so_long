#include "so_long.h"

void take_thecoins(mlx *s, int x, int y)
{
	void *texture;
	void *ground;

	if (s->map[y][x] == 'C')
	{
		s->coins -= 1;
		s->map[y][x] = '0';
		texture = mlx_load_png("imgs/ground.png");
		ground = mlx_texture_to_image(s->mlx, texture);
		mlx_delete_texture(texture);
		mlx_image_to_window(s->mlx, ground, x * 60, y * 60);
		mlx_delete_image(s->mlx, s->player);
		texture = mlx_load_png("imgs/player.png");
		s->player = mlx_texture_to_image(s->mlx, texture);
		mlx_image_to_window(s->mlx, s->player, x * 60, y * 60);
		mlx_delete_texture(texture);
	}
	else if (s->map[y][x] == 'E' && s->coins == 0)
	{
		exit(0);
	}
	if (s->coins == 0)
		get_coins(s, s->mlx);
}

void my_keys(mlx_key_data_t keydata, void *param)
{
    mlx *s;
    int x;
    int y;

    s = (mlx *)param;
    x = s->player->instances->x / 60;
    y = s->player->instances->y / 60;

    if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS) && s->map[y - 1][x] != '1')
		s->player->instances->y -= 60;
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS) && s->map[y + 1][x] != '1')
		s->player->instances->y += 60;
    if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS) && s->map[y][x + 1] != '1')
		s->player->instances->x += 60;
    if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS) && s->map[y][x - 1] != '1')
		s->player->instances->x -= 60;
    if (keydata.key == MLX_KEY_ESCAPE)
        exit(1);
	x = s->player->instances->x / 60;
    y = s->player->instances->y / 60;
	take_thecoins(s, x, y);
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
			if (s->map[y][x] == '1')
				texture = mlx_load_png("imgs/wall.png");
			else
				texture = mlx_load_png("imgs/ground.png");
			image = mlx_texture_to_image(mlx, texture);
			mlx_image_to_window(mlx, image, x * 60, y * 60);
			mlx_delete_texture(texture);
			x++;
		}
		y++;
	}
}
void	start(mlx *s)
{
	void *texture;

	s->mlx = mlx_init(s->width,  s->height, "so_long", 0);
	get_walls_ground(s, s->mlx);
	get_coins(s, s->mlx);
	texture = mlx_load_png("imgs/player.png");
	s->player = mlx_texture_to_image(s->mlx, texture);
	mlx_image_to_window(s->mlx, s->player, s->x, s->y);
	mlx_delete_texture(texture);
}