/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:30:59 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/13 04:30:59 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_first_and_last_line(char **map_content, int y)
{
	int	x;

	x = 0;
	if (!map_content || !map_content[y] || !map_content[y][x])
		return (FAILURE);
	while (is_whitespace(map_content[y][x]))
		x++;
	while (map_content[y][x])
	{
		if (map_content[y][x] != '1')
			return (FAILURE);
		x++;
	}
	return (SUCCESS);
}

int	check_outline(t_map *map)
{
	int	y;
	int	x;

	if (!check_first_and_last_line(map->content, 0))
		return (FAILURE);
	y = 1;
	while (y < (map->row - 1))
	{
		x = 0;
		while (is_whitespace(map->content[y][x]))
			x++;
		if (map->content[y][x] != '1')
			return (FAILURE);
		x = ft_strlen(map->content[y]) - 1;
		if (map->content[y][x] != '1')
			return (FAILURE);
		y++;
	}
	if (!check_first_and_last_line(map->content, y))
		return (FAILURE);
	return (SUCCESS);
}
