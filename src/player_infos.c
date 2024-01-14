/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:42:13 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/11 20:12:30 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_coordinates(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map->content[i])
	{
		j = ft_strsearch_chars(map->content[i], "NSWE");
		if (map->content[i][j])
			break ;
		i++;
	}
	player->y = i;
	player->x = j;
	player->dir = map->content[i][j];
	map->content[i][j] = '0';
}

void	set_player_direction(t_player *player)
{
	if (player->dir == 'N')
	{
		player->dir_y = -1;
		player->plane_x = 0.66;
	}
	if (player->dir == 'S')
	{
		player->dir_y = 1;
		player->plane_x = -0.66;
	}
	if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->plane_y = 0.66;
	}
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->plane_y = -0.66;
	}
}
