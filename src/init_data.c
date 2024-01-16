/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam </var/spool/mail/sam>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:13:13 by sam               #+#    #+#             */
/*   Updated: 2024/01/14 17:31:05 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map(t_map *map)
{
	map->f_content = NULL;
	map->col = 0;
	map->row = 0;
	map->content = NULL;
	map->f_content = NULL;
}

static void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->dir = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
}

static void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->walldist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

static void	init_texture(t_texture *tex)
{
	tex->x = 0;
	tex->y = 0;
	tex->pos = 0;
	tex->step = 0;
	tex->north = NULL;
	tex->south = NULL;
	tex->east = NULL;
	tex->west = NULL;
	tex->floor = 0;
	tex->ceiling = 0;
}

int	init_data(t_game *game)
{
	init_map(&game->map);
	init_player(&game->player);
	init_ray(&game->ray);
	init_texture(&game->texture);
	return (0);
}
