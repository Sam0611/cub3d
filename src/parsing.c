/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:40:01 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/14 11:58:56 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

#include <stdio.h> //tmp
int	check_map_character(t_map *map)
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
				return (print_error("invalid map character\n"));
			if (ft_strchr("EWNS", map->content[y][x]))
			{
				if (map->p_dir == 'U')
					map->p_dir = map->content[y][x];
				else
					return (print_error("multiple definition of start\n"));
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_texture_file(char *tex_path)
{
	int	len;
	int	fd;

	len = ft_strlen(tex_path) - 4;
	if (len <= 0 || ft_strncmp(tex_path + len, ".png", 5))
	{
		print_error("texture file is not .png\n");
		return (0);
	}
	fd = open(tex_path, O_DIRECTORY);
	if (fd != -1)
	{
		perror(tex_path);
		return (0);
	}
	fd = open(tex_path, O_RDONLY);
	if (fd < 0)
	{
		perror(tex_path);
		return (0);
	}
	close(fd);
	return (1);
}

int	check_textures(t_tex *tex)
{
	int	i;

	if (!check_texture_file(tex->east)
		|| !check_texture_file(tex->west)
		|| !check_texture_file(tex->north)
		|| !check_texture_file(tex->south))
		return (0);
	i = 0;
	while (i < 3)
	{
		if (tex->floor[i] < 0 || tex->floor[i] > 255)
			return (print_error("invalid floor RGB color"));
		if (tex->ceiling[i] < 0 || tex->ceiling[i] > 255)
			return (print_error("invalid ceiling RGB color"));
		i++;
	}
	return (1);
}

int	check_data(t_map *map, t_tex *tex)
{
	print_error("debug check_data");
	if (!map->content)
		return (print_error("no map"));
	if (map->row < 3 || map->col < 3)
		return (print_error("map is too small"));
	if (!tex->floor || !tex->ceiling)
		return (print_error("missing color"));
	if (!tex->east || !tex->west || !tex->north || !tex->south)
		return (print_error("missing texture"));
	printf("Debug: floor = %d %d %d\n", tex->floor[0], tex->floor[1], tex->floor[2]);
	//int i = 0;
	//while (map->content[i])
	//	printf("%s\n", map->content[i++]); //tmp debug
	return (1);
}

int	parse_map(t_game *game, t_map *map)
{
	if (!check_data(map, &game->textures))
		return (0);
	if (!check_outline(map))
		return (print_error("map is not surounded by wall\n"));
	if (!check_textures(&game->textures))
		return (0);
	if (!check_map_character(map))
		return (0);
	printf("debug: parse_map: OK\n");
	return (1);
}

void	get_map(char *filename, t_map *map, t_game *game)
{
	initialize(game, map);
	map->name = filename;
	if (!get_file_content(map))
		exit(0); //free
	if (!read_file(map, game))
		exit(0); //free
	if (!parse_map(game, map))
		exit(0); //free
	printf("debug: get_map: OK\n");
}

//todo list
// - print error messages
// - free before exit
// - wall
// - xpm conversion
