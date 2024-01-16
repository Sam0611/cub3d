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
    game->texture->x = (int)(ray->wall_x * TEX_SIZE);
	if ((ray->side == 0 && ray->dir_x < 0) // > 0
		|| (ray->side == 1 && ray->dir_y > 0)) // < 0
		game->texture->x = TEX_SIZE - game->texture->x - 1;
	game->texture->step = 1.0 * TEX_SIZE / ray->line_height;
	game->texture->pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * game->texture->step;
}
