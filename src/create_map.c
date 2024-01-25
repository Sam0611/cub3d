/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:14:17 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/13 04:14:17 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_row(t_map *map, char **f_content, int y);
int	count_col(char **f_content, int y);

static int	fill_map(t_map *map, int f_row)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->row)
	{
		x = 0;
		map->content[y] = malloc(sizeof(char) * (map->col + 1));
		if (!map->content[y])
			return (print_error("failed to allocate memory"));
		while (map->f_cont[f_row][x] && map->f_cont[f_row][x] != '\n')
		{
			map->content[y][x] = map->f_cont[f_row][x];
			x++;
		}
		while (x < map->col)
		{
			map->content[y][x] = ' ';
			x++;
		}
		map->content[y][x] = '\0';
		f_row++;
	}
	map->content[y] = NULL;
	return (SUCCESS);
}

bool	is_adjacent_to_zero(t_map *map, int y, int x)
{
	if ((y > 0 && ft_strchr("0NSEW", map->content[y - 1][x]))
		|| (y < map->row - 1 && ft_strchr("0NSEW", map->content[y + 1][x])))
		return (true);
	else if (x > 0 && ft_strchr("0NSEW", map->content[y][x - 1]))
		return (true);
	else if (x < map->content[y][ft_strlen(map->content[y]) - 1]
		&& ft_strchr("0NSEW", map->content[y][x + 1]))
		return (true);
	return (false);
}

int	fill_void(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->content[y])
	{
		x = 0;
		while (is_whitespace(map->content[y][x]))
			x++;
		while (map->content[y][x])
		{
			if (map->content[y][x] == ' '
				&& x < (int)ft_strlen(map->content[y]))
			{
				if (is_adjacent_to_zero(map, y, x))
					return (FAILURE);
				map->content[y][x] = '1';
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	check_end_of_file(t_map *map)
{
	int	y;
	int	x;

	y = map->eom;
	while (map->f_cont[y])
	{
		x = 0;
		while (map->f_cont[y][x])
		{
			if (!is_whitespace(map->f_cont[y][x]))
				return (FAILURE);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	get_map_content(t_map *map, int y)
{
	map->col = count_col(map->f_cont, y);
	map->row = count_row(map, map->f_cont, y);
	if (!check_end_of_file(map))
	{
		print_error("map is not at the end of file");
		return (FAILURE);
	}
	map->content = (char **)malloc(sizeof(char *) * (map->row + 1));
	if (!map->content)
	{
		print_error("failed to allocate memory for the map");
		return (FAILURE);
	}
	if (!fill_map(map, y))
		return (FAILURE);
	if (!fill_void(map))
	{
		print_error("hole in map, tiles must be surounded by wall");
		return (FAILURE);
	}
	return (SUCCESS);
}
