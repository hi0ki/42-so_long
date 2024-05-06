#include <stdio.h>
#include "so_long.h"

typedef struct s_mlx
{
    int x;
    void *mlx;
        void *img;

} t_mlx;

void loop_hook(void *param)
{
    t_mlx *test = (t_mlx *)param;
    void *texture;

    test->x += 1;
    if (test->x > 75)
        test->x = 0;
    if (test->x == 20)
    {
            mlx_delete_image(test->mlx, test->img);
        texture = mlx_load_png("imgs/Money1.png");
        test->img = mlx_texture_to_image(test->mlx, texture);
        mlx_image_to_window(test->mlx, test->img, 0, 0);
        mlx_delete_texture(texture);
    }
    else if (test->x == 35)
    {  
            mlx_delete_image(test->mlx, test->img);
        texture = mlx_load_png("imgs/Money2.png");
        test->img = mlx_texture_to_image(test->mlx, texture);
        mlx_image_to_window(test->mlx, test->img, 0, 0);
        mlx_delete_texture(texture);
    }
    else if (test->x == 55)
    {
            mlx_delete_image(test->mlx, test->img);
        texture = mlx_load_png("imgs/Money3.png");
        test->img = mlx_texture_to_image(test->mlx, texture);
        mlx_image_to_window(test->mlx, test->img, 0, 0);
        mlx_delete_texture(texture);
    }
    else if (test->x == 65)
    {
            mlx_delete_image(test->mlx, test->img);
        texture = mlx_load_png("imgs/Money4.png");
        test->img = mlx_texture_to_image(test->mlx, texture);
        mlx_image_to_window(test->mlx, test->img, 0, 0);
        mlx_delete_texture(texture);
    }
    else if (test->x == 75)
    {
            mlx_delete_image(test->mlx, test->img);
        texture = mlx_load_png("imgs/Money5.png");
        test->img = mlx_texture_to_image(test->mlx, texture);
        mlx_image_to_window(test->mlx, test->img, 0, 0);
        mlx_delete_texture(texture);
    }
}

int main()
{
    t_mlx test;

    test.x = 15;
    test.mlx = mlx_init(500, 300, "mehdi", 0);
    mlx_loop_hook(test.mlx, loop_hook, &test);
    mlx_loop(test.mlx);
}