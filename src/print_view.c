/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:05:13 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/17 19:18:56 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_texture_infos(t_texture *tex, t_ray *ray)
{
	tex->x = (int)(ray->wall_x * TEX_SIZE);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = TEX_SIZE - tex->x - 1;
	tex->step = 1.0 * TEX_SIZE / ray->line_height;
	tex->pos = (ray->draw_start - HEIGHT / 2
			+ ray->line_height / 2) * tex->step;
}

static void	put_texture_pixels(t_game *game, t_texture *tex, int x, int y)
{
	unsigned int	color;
	mlx_texture_t	*tex_data;

	tex_data = tex->north;
	if (game->ray.side == 0 && game->ray.dir_x < 0)
		tex_data = tex->west;
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		tex_data = tex->east;
	if (game->ray.side == 1 && game->ray.dir_y > 0)
		tex_data = tex->south;
	tex->y = (int)tex->pos & (TEX_SIZE - 1);
	tex->pos += tex->step;
	color = tex_data->pixels[(tex->x + tex->y * TEX_SIZE)
		* tex_data->bytes_per_pixel] << 24;
	color |= tex_data->pixels[(tex->x + tex->y * TEX_SIZE)
		* tex_data->bytes_per_pixel + 1] << 16;
	color |= tex_data->pixels[(tex->x + tex->y * TEX_SIZE)
		* tex_data->bytes_per_pixel + 2] << 8;
	color |= tex_data->pixels[(tex->x + tex->y * TEX_SIZE)
		* tex_data->bytes_per_pixel + 3];
	mlx_put_pixel(game->image, x, y, color);
}

void	print_vertical_line(int x, t_game *game, t_ray *ray)
{
	int				y;

	update_texture_infos(&game->texture, ray);
	y = 0;
	while (y < (int)game->image->height)
	{
		if (y < ray->draw_start)
			mlx_put_pixel(game->image, x, y, game->texture.ceiling);
		else if (y > ray->draw_end)
			mlx_put_pixel(game->image, x, y, game->texture.floor);
		else
			put_texture_pixels(game, &game->texture, x, y);
		y++;
	}
	return ;
}
