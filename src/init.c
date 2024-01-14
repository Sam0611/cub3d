/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:12:15 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/13 04:12:15 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_texture_struct(t_tex *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->east = NULL;
	texture->west = NULL;
	texture->floor = 0;
	texture->ceiling = 0;
}

void	initialize(t_game *game, t_map *map)
{
	init_texture_struct(&game->textures);
	map->f_content = NULL;
	map->col = 0;
	map->row = 0;
	map->p_dir = 'U';
	map->content = NULL;
	map->f_content = NULL;
}
