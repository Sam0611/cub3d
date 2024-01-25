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

char	**split_newline_string(char *str);

int	get_file_content(t_map *map)
{
	int			fd;
	char		*tmp;

	fd = open(map->name, O_RDONLY);
	if (fd < 0)
	{
		print_error(strerror(errno));
		return (FAILURE);
	}
	tmp = get_all_lines(fd);
	map->f_cont = split_newline_string(tmp);
	free(tmp);
	close(fd);
	if (!map->f_cont)
	{
		print_error("memory allocation failed");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	is_param(t_map *map, t_game *game, int y, int x)
{
	if (map->f_cont[y][x + 1] && ft_isprint(map->f_cont[y][x + 1]))
	{
		if (!get_texture_infos(&game->texture, map->f_cont[y]))
			return (FAILURE);
	}
	else
	{
		if (!init_color(&game->texture, map->f_cont[y], x))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	read_file(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map->f_cont[y])
	{
		x = 0;
		while (map->f_cont[y][x])
		{
			while (map->f_cont[y][x] && ft_strchr(" \t", map->f_cont[y][x]))
				x++;
			if (!ft_isdigit(map->f_cont[y][x]) && ft_isprint(map->f_cont[y][x]))
			{
				if (!is_param(map, game, y, x))
					return (FAILURE);
				break ;
			}
			else if (ft_isdigit(map->f_cont[y][x]))
				return (get_map_content(map, y));
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
