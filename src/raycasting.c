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

void	print_vertical_line(int x, t_game *game, t_ray *ray);

static void	init_raycasting_info(int i, t_ray *ray, t_player *player)
{
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->camera_x = 2 * i / (double)WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

static void	set_dda_values(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->y) * ray->deltadist_y;
	}
}

static void	apply_dda(char **map, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > HEIGHT - 0.25 || ray->map_x > WIDTH - 1.25)
			break ;
		else if (map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

static void	get_line_height(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->walldist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->walldist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(HEIGHT / ray->walldist);
	ray->draw_start = -(ray->line_height) / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT || ray->draw_end < 0)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->y + ray->walldist * ray->dir_y;
	else
		ray->wall_x = player->x + ray->walldist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	raycasting(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		init_raycasting_info(i, game->ray, game->player);
		set_dda_values(game->ray, game->player);
		apply_dda(game->map->content, game->ray);
		get_line_height(game->ray, game->player);
		print_vertical_line(i, game, game->ray);
		i++;
	}
}
