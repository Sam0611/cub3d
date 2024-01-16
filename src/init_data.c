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

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		print_error("memory allocation failed");
	player->x = 0;
	player->y = 0;
	player->dir = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	return (player);
}

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		print_error("memory allocation failed");
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
	return (ray);
}

t_texture	*init_texture(void)
{
	t_texture	*tex;

	tex = malloc(sizeof(t_texture));
	if (!tex)
		print_error("memory allocation failed");
	tex->data = mlx_load_png("img/sonic.png");
	if (!tex || !tex->data)
		return (NULL);
	tex->x = 0;
	tex->y = 0;
	tex->pos = 0;
	tex->step = 0;
	if (tex->data->width != TEX_SIZE || tex->data->height != TEX_SIZE)
	{
		print_error("Wrong image size, must be 256x256");
		return (NULL);
	}
	return (tex);
}

int	init_data(t_game *game)
{
	mlx_image_t		*image;

	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game->mlx)
		return (1);
	image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!image || mlx_image_to_window(game->mlx, image, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		print_error("Failed to print game screen");
		return (1);
	}
	game->image = image;
	return (0);
}
