#include "so_long.h"

typedef struct mehdi {
    void *mlx;
}mehdi;
void my_coin(void *param)
{

}
int main()
{
    mehdi str;
    void *texture;
	void *img;

    str.mlx = mlx_init(1000, 1000, "mehdi", 0);
	texture = mlx_load_png("imgs/coin1.png");
	img = mlx_texture_to_image(str.mlx, texture);
	mlx_image_to_window(str.mlx, img, 1 * 60, 1 * 60);
    mlx_loop_hook(str.mlx, my_coin, str.mlx);
    mlx_loop(str.mlx);
}