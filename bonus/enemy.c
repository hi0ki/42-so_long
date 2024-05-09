#include "so_long_bonus.h"

void	get_enemy(t_mlx *s, t_emy *str)
{
    
}

void enemy_move(t_mlx *s, t_emy *str)
{
    int x;
    int y;

    y = 0;
    while (s->map[y])
    {
        x = 0;
        while(s->map[y][x])
        {
            get_enemy(s)
        }
    }
}

void start_enemy(void *param)
{
    t_emy str;
    t_mlx *s;

    s = (t_emy *)param;
    if (i == 10)
        i = 0;
    if (i == 9)
    {
        if (j == 4)
            j = 0;
        enemy_move(s, str);
    }
    i++;
}