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

static void	apply_dda(char **map, t_ray *ray)
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
		else if (map[ray->mapY][ray->mapX] == '1')
			hit = 1;
	}
}

static void	get_line_height(t_ray *ray, t_player player)
{
	if (ray->side == 0)
		ray->walldist = (ray->sidedistX - ray->deltadistX);
	else
		ray->walldist = (ray->sidedistY - ray->deltadistY);
	ray->line_height = (int)(HEIGHT / ray->walldist);
	ray->draw_start = -(ray->line_height) / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wallX = player.y + ray->walldist * ray->dirY;
	else
		ray->wallX = player.x + ray->walldist * ray->dirX;
	ray->wallX -= floor(ray->wallX);
}

void	update_texture_pixels(t_wall *wall, t_ray *ray)
{
	int			j;

	wall->x = (int)(ray->wallX * WALL_SIZE);
	if ((ray->side == 0 && ray->dirX < 0)
		|| (ray->side == 1 && ray->dirY > 0))
		wall->x = WALL_SIZE - wall->x - 1;
	wall->step = 1.0 * WALL_SIZE / ray->line_height;
	wall->pos = (ray->draw_start - HEIGHT / 2
			+ ray->line_height / 2) * wall->step;
	j = ray->draw_start;
	while (j < ray->draw_end)
	{
		wall->y = (int)wall->pos & (WALL_SIZE - 1);
		wall->pos += wall->step;
		j++;
	}
}

void	raycasting(t_game game, t_ray *ray, t_wall *wall)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		init_raycasting_info(i, ray, game.player);
		set_dda_values(ray, game.player);
		apply_dda(game.map->content, ray);
		get_line_height(ray, game.player);
		update_texture_pixels(wall, ray);
		i++;
	}
}
