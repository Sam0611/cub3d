/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:40:01 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/28 22:04:06 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_character(t_map *map, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			while (map->content[y][x] == ' ')
				x++;
			if (!(ft_strchr("EWNS01", map->content[y][x])))
				return (print_error("invalid map character"));
			if (ft_strchr("EWNS", map->content[y][x]))
			{
				if (player->dir == 0)
					player->dir = map->content[y][x];
				else
					return (print_error("multiple definition of start"));
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

static int	check_data(t_map *map, t_texture tex)
{
	if (!map->content)
	{
		print_error("no map");
		return (FAILURE);
	}
	if (map->row < 3 || map->col < 3)
	{
		print_error("bad map");
		return (FAILURE);
	}
	if (!tex.floor || !tex.ceiling)
	{
		print_error("wrong color parameters");
		return (FAILURE);
	}
	if (!tex.east || !tex.west || !tex.north || !tex.south)
	{
		print_error("missing texture");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	parse_map(t_game *game, t_map *map)
{
	if (!check_data(map, game->texture))
		return (FAILURE);
	if (!check_map_character(map, &game->player))
		return (FAILURE);
	if (!check_outline(map))
	{
		print_error("map is not surounded by wall");
		return (FAILURE);
	}
	if (game->player.dir == 0)
	{
		print_error("no start position");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	error_free(t_game *game)
{
	if (game->map.content)
		free_tab(game->map.content);
	if (game->map.f_cont)
		free_tab(game->map.f_cont);
	if (game->texture.north)
		mlx_delete_texture(game->texture.north);
	if (game->texture.south)
		mlx_delete_texture(game->texture.south);
	if (game->texture.east)
		mlx_delete_texture(game->texture.east);
	if (game->texture.west)
		mlx_delete_texture(game->texture.west);
	return (FAILURE);
}

void	get_map(char *filename, t_game *game)
{
	game->map.name = filename;
	if (!get_file_content(&game->map))
	{
		error_free(game);
		exit(5);
	}
	if (!read_file(&game->map, game))
	{
		error_free(game);
		exit(6);
	}
	if (!parse_map(game, &game->map))
	{
		error_free(game);
		exit(7);
	}
	free_tab(game->map.f_cont);
}
