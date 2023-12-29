/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:36:47 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/29 15:36:49 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_raycasting_info(int i, t_ray *ray, t_player player)
{
	//init_ray(ray); put all values to 0
	ray->mapX = (int)player.x;
	ray->mapY = (int)player.y;
	ray->cameraX = 2 * i / (double)WIDTH - 1;
	ray->dirX = player.dirX + player.planeX * ray->cameraX;
	ray->dirY = player.dirY + player.planeY * ray->cameraX;
	ray->deltadistX = fabs(1 / ray->dirX);
	ray->deltadistY = fabs(1 / ray->dirY);
}

static void	set_dda_values(t_ray *ray, t_player player)
{
	if (ray->dirX < 0)
	{
		ray->stepX = -1;
		ray->sidedistX = (player.x - ray->mapX) * ray->deltadistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sidedistX = (ray->mapX + 1.0 - player.x) * ray->deltadistX;
	}
	if (ray->dirY < 0)
	{
		ray->stepY = -1;
		ray->sidedistY = (player.y - ray->mapY) * ray->deltadistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sidedistY = (ray->mapY + 1.0 - player.y) * ray->deltadistY;
	}
}

static void	apply_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedistX < ray->sidedistY)
		{
			ray->sidedistX += ray->deltadistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sidedistY += ray->deltadistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (ray->mapY < 0.25 || ray->mapX < 0.25
			|| ray->mapY > HEIGHT - 0.25 || ray->mapX > WIDTH - 1.25)
			break ;
		else if (game->map->content[ray->mapY][ray->mapX] == '1')
			hit = 1;
	}
}

void	raycasting(t_game *game, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		init_raycasting_info(i, ray, game->player);
		set_dda_values(ray, game->player);
		apply_dda(game, ray);
		i++;
	}
}
