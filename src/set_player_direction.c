
#include "cub3d.h"

void    set_player_direction(t_player *player)
{
    player->dirX = 0;
    player->dirY = 0;
    player->planeX = 0;
    player->planeY = 0;
    if (player->dir == 'N')
    {
        player->dirY = -1;
        player->planeX = 0.66;
    }
    if (player->dir == 'S')
    {
        player->dirY = 1;
        player->planeX = -0.66;
    }
    if (player->dir == 'E')
    {
        player->dirX = 1;
        player->planeY = 0.66;
    }
    if (player->dir == 'W')
    {
        player->dirX = -1;
        player->planeY = -0.66;
    }
}