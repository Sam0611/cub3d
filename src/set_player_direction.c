/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_direction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:42:13 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/30 16:42:19 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
