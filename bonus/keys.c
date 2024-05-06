#include "so_long.h"

void take_thecoins(mlx *s, int x, int y, char *str)
{
	void *texture;
	void *ground;

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

void left_right(mlx_key_data_t keydata, mlx *s, int x,int y)
{
    if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS) && s->map[y][x + 1] != '1')
	{
		s->player->instances->x += 60;
		get_player(s, "imgs/to_right.png", (x + 1) * 60,y * 60);
	}
    else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS) && s->map[y][x - 1] != '1')
	{
		s->player->instances->x -= 60;
		get_player(s, "imgs/to_left.png", (x - 1) * 60, y * 60);
	}
    if (keydata.key == MLX_KEY_D)
        take_thecoins(s, x + 1, y, "imgs/to_right.png");
    else if (keydata.key == MLX_KEY_A)
        take_thecoins(s, x - 1, y, "imgs/to_left.png");
}

void top_bot(mlx_key_data_t keydata, mlx *s, int x, int y)
{
    if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS) && s->map[y - 1][x] != '1')
    {
		s->player->instances->y -= 60;
        get_player(s, "imgs/to_top.png", x * 60, (y - 1) * 60);
    }
    else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS) && s->map[y + 1][x] != '1')
	{
		s->player->instances->y += 60;
        get_player(s, "imgs/to_bot.png", x * 60, (y + 1) * 60);
    }
    if (keydata.key == MLX_KEY_W)
        take_thecoins(s, x, y - 1, "imgs/to_top.png");
    else if (keydata.key == MLX_KEY_S)
        take_thecoins(s, x, y + 1, "imgs/to_bot.png");
}

void my_keys(mlx_key_data_t keydata, void *param)
{
    mlx *s;
    int x;
    int y;

    s = (mlx *)param;
    x = s->player->instances->x / 60;
    y = s->player->instances->y / 60;
    if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
        top_bot(keydata, s, x, y);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_A )
	    left_right(keydata, s, x, y);
	else if (keydata.key == MLX_KEY_ESCAPE)
        exit(1);
}