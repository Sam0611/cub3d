/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:31:21 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/13 05:40:58 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

int	get_map_content(t_map *map)
{
	int			fd;
	char		*tmp;

	fd = open(map->name, O_RDONLY);
	if (fd < 0)
		return (1); //print error, free
	tmp = get_all_lines(fd);
	map->content = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (0);
}

int	count_row(char *map_name)
{
	char	*line;
	int		count;
	int		fd;

	fd = open(map_name, O_RDWR, S_IRWXU);
	if (fd < 0)
	{
		perror(map_name);
		exit(1);
	}
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static void	get_map(char *map_name, t_map *map)
{
	map->name = map_name;
	map->row = count_row(map_name);
	if (get_map_content(map))
		exit(1);
}

static int	check_file(char *map_name)
{
	int	len;
	int	fd;

	len = ft_strlen(map_name) - 4;
	if (len <= 0 || ft_strncmp(map_name + len, ".cub", 5))
	{
		printf("Error\nFile not valid\n"); // afficher dans sortie 2
		return (1);
	}
	fd = open(map_name, O_DIRECTORY);
	if (fd != -1)
	{
		perror(map_name);
		exit(1);
	}
	fd = open(map_name, O_RDWR, S_IRWXU);
	if (fd < 0)
	{
		perror(map_name);
		exit(1);
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_map		map;
	t_game		game;

	if (ac != 2)
		return (0);
	if (check_file(av[1]))
		return (0);
	get_map(av[1], &map);
	if (!map.content)
		return (1);
	map.row = 0;
	while (map.content[map.row])
		map.row++;
	game.map = &map;

	print_map(game);

	return (0);
}
