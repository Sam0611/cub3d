/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:31:16 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/14 17:31:39 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_texture_infos(t_game *game, t_ray *ray)
{
    // int i;

    game->texture->x = (int)(ray->wall_x * game->texture->width);
	if ((ray->side == 0 && ray->dir_x < 0) // > 0
		|| (ray->side == 1 && ray->dir_y > 0)) // < 0
		game->texture->x = game->texture->width - game->texture->x - 1;
	game->texture->step = 1.0 * game->texture->height / ray->line_height;
	game->texture->pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * game->texture->step;
	// i = ray->draw_start;
	// while (i < ray->draw_end)
	// {
	// 	game->texture->y = (int)game->texture->pos & (game->texture->height - 1);
	// 	game->texture->pos += game->texture->step;
	// 	i++;
	// }
}
