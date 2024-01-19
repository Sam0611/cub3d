/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:23:26 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/13 04:23:26 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_file_content(t_map *map)
{
	int			fd;
	char		*tmp;

	fd = open(map->name, O_RDONLY);
	if (fd < 0)
		return (print_error(strerror(errno)));
	tmp = get_all_lines(fd);
	map->f_content = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	if (!map->f_content)
		return (print_error("memory allocation failed"));
	return (1);
}

static int	is_param(t_map *map, t_game *game, int y, int x)
{
	if (map->f_content[y][x + 1] && ft_isprint(map->f_content[y][x + 1]))
	{
		if (!get_texture_infos(&game->texture, map->f_content[y]))
			return (0);
	}
	else
	{
		if (!init_color(&game->texture, map->f_content[y], x))
			return (0);
	}
	return (1);
}

int	read_file(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map->f_content[y])
	{
		x = 0;
		while (map->f_content[y][x])
		{
			while (map->f_content[y][x] && ft_strchr(" \t\n", map->f_content[y][x]))
				x++;
			if (!ft_isdigit(map->f_content[y][x]) && ft_isprint(map->f_content[y][x]))
			{
				if (!is_param(map, game, y, x))
					return (0);
				break ;
			}
			else if (ft_isdigit(map->f_content[y][x]))
				return (get_map_content(map, y));
			x++;
		}
		y++;
	}
	return (1);
}
