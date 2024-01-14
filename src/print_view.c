/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:05:13 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/30 17:05:15 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fct(t_game *game, t_texture *tex, int x, int y)
{
	unsigned int	color;

	game->texture->y = (int)game->texture->pos & (tex->height - 1);
	game->texture->pos += tex->step;
	color = tex->data->pixels[(tex->x + game->texture->y * tex->width) * tex->data->bytes_per_pixel] << 24;
	color |= tex->data->pixels[(tex->x + game->texture->y * tex->width) * tex->data->bytes_per_pixel + 1] << 16;
	color |= tex->data->pixels[(tex->x + game->texture->y * tex->width) * tex->data->bytes_per_pixel + 2] << 8;
	color |= tex->data->pixels[(tex->x + game->texture->y * tex->width) * tex->data->bytes_per_pixel + 3];
	mlx_put_pixel(game->image, x, y, color);
}

void	print_vertical_line(int x, t_game *game, t_ray *ray)
{
	int				y;
	// unsigned int	wall_color;

	// wall_color = get_color(YELLOW);
	// if (ray->side != 1)
	// 	wall_color /= 1.5;
	y = 0;
	while (y < (int)game->image->height)
	{
		if (y < ray->draw_start)
			mlx_put_pixel(game->image, x, y, get_color(BLUE));
		else if (y > ray->draw_end)
			mlx_put_pixel(game->image, x, y, get_color(GREEN));
		else
			fct(game, game->texture, x, y);
		y++;
	}
	return ;
}
