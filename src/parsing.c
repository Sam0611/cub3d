/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:40:01 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/19 16:35:38 by sbeaucie         ###   ########.fr       */
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
			while (is_whitespace(map->content[y][x]))
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
	return (1);
}

static int	check_data(t_map *map, t_texture tex)
{
	if (!map->content)
		return (print_error("no map"));
	if (map->row < 3 || map->col < 3)
		return (print_error("bad map"));
	if (!tex.floor || !tex.ceiling)
		return (print_error("wrong color parameters"));
	if (!tex.east || !tex.west || !tex.north || !tex.south)
		return (print_error("missing texture"));
	return (1);
}

static int	parse_map(t_game *game, t_map *map)
{
	if (!check_data(map, game->texture))
		return (0);
	if (!check_outline(map))
		return (print_error("map is not surounded by wall"));
	if (!check_map_character(map, &game->player))
		return (0);
	if (game->player.dir == 0)
		return (print_error("no start position"));
	return (1);
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
	return (0);
}

void	get_map(char *filename, t_game *game)
{
	game->map.name = filename;
	if (!get_file_content(&game->map))
		exit(error_free(game));
	if (!read_file(&game->map, game))
		exit(error_free(game));
	if (!parse_map(game, &game->map))
		exit(error_free(game));
	free_tab(game->map.f_cont);
}
