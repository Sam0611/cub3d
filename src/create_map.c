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

static int	count_row(char **f_content, int y)
{
	int			x;
	int			first_row;
	static char	*whitespace = " \t\r\v\f";

	first_row = y;
	while (f_content[y])
	{
		x = 0;
		while (f_content[y][x] && ft_strchr(whitespace, f_content[y][x]))
			x++;
		if (f_content[y][x] != '1')
			break ;
		y++;
	}
	return (y - first_row);
}

static int	count_col(char **f_content, int y)
{
	int	res;
	int	line_size;

	res = ft_strlen(f_content[y]);
	while (f_content[y])
	{
		line_size = ft_strlen(f_content[y]);
		if (res < line_size)
			res = line_size;
		y++;
	}
	return (res);
}

static int	fill_map(t_map *map, int f_row)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		map->content[y] = malloc(sizeof(char) * (map->col + 1));
		if (!map->content[y])
			return (print_error("failed to allocate memory"));
		while (map->f_content[f_row][x] && map->f_content[f_row][x] != '\n')
		{
			map->content[y][x] = map->f_content[f_row][x];
			x++;
		}
		while (x < map->col)
		{
			map->content[y][x] = ' ';
			x++;
		}
		map->content[y][x] = '\0';
		y++;
		f_row++;
	}
	map->content[y] = NULL;
	return (1);
}

bool is_adjacent_to_zero(t_map *map, int y, int x) 
{
	if ((y > 0 && map->content[y - 1][x] == '0') 
		|| (y < map->row - 1 && map->content[y + 1][x] == '0'))
		return (true);
	else if (x > 0 && map->content[y][x - 1] == '0')
		return (true);
	else if (x < map->content[y][ft_strlen(map->content[y]) - 1] 
		&& map->content[y][x + 1] == '0')
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
			if (map->content[y][x] == ' ' && x < (int)ft_strlen(map->content[y]))
			{
				if (is_adjacent_to_zero(map, y, x))
                    return (0);
				map->content[y][x] = '1';
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	get_map_content(t_map *map, int y)
{
	map->row = count_row(map->f_content, y);
	map->col = count_col(map->f_content, y);
	map->content = (char **)malloc(sizeof(char *) * (map->row + 1));
	if (!map->content)
		return (print_error("failed to allocate memory"));
	if (!fill_map(map, y))
		return (0);
	if (!fill_void(map))
		return (print_error("hole in map"));
	return (1);
}
