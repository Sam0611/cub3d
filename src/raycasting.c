/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:36:47 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/23 21:58:34 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_vertical_line(int x, t_game *game, t_ray *ray);

//camera_x is the x coordinate on the camera plane that i represents
//plane_x/y is the camera plane of the player
//the camera plane is perpendicular to the direction
static void	calculate_distance_between_sides(int i,
	t_ray *ray, t_player *player)
{
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->camera_x = 2 * i / (double)WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->sidedist_x = fabs(1 / ray->dir_x);
	ray->sidedist_y = fabs(1 / ray->dir_y);
}

// startdist is the distance between start position and the first x/y side
// sidedist is the distance between 2 x/y side
// step is the x/y direction to step in
static void	calculate_distance_from_start_to_side(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->startdist_x = (player->x - ray->map_x) * ray->sidedist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->startdist_x = (ray->map_x + 1.0 - player->x) * ray->sidedist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->startdist_y = (player->y - ray->map_y) * ray->sidedist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->startdist_y = (ray->map_y + 1.0 - player->y) * ray->sidedist_y;
	}
}

// line from one x (or y) coordinate to another
static void	hit_wall(char **map, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->startdist_x < ray->startdist_y)
		{
			ray->startdist_x += ray->sidedist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->startdist_y += ray->sidedist_y;
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

// wall_x is where wall was hit
static void	get_line_height(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->walldist = (ray->startdist_x - ray->sidedist_x);
	else
		ray->walldist = (ray->startdist_y - ray->sidedist_y);
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
		calculate_distance_between_sides(i, &game->ray, &game->player);
		calculate_distance_from_start_to_side(&game->ray, &game->player);
		hit_wall(game->map.content, &game->ray);
		get_line_height(&game->ray, &game->player);
		print_vertical_line(i, game, &game->ray);
		i++;
	}
}
