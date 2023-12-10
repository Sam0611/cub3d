/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:31:21 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/08 16:31:23 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

static char	*get_map(char *map_name)
{
	int		fd;
	char	*map;

	fd = open(map_name, O_RDWR, S_IRWXU);
	if (fd < 0)
	{
		perror(map_name);
		return (NULL);
	}
	map = get_all_lines(fd);
	close(fd);
	return (map);
}

static int	check_map_name(char *map_name)
{
	int	len;

	len = ft_strlen(map_name) - 4;
	if (len <= 0 || ft_strncmp(map_name + len, ".cub", 5))
	{
		printf("Error\nFile not valid\n"); // afficher dans sortie 2
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map		map;
	int			i;

	if (ac != 2)
		return (0);
	if (check_map_name(av[1]))
		return (0);
	map.content = get_map(av[1]);
	if (!map.content)
		return (1);
	i = ft_strlen(map.content) - 1;
	map.col = ft_strsearch(map.content, '\n');
	map.row = ft_countchar('\n', map.content);
	if (map.content[i] != '\n')
		map.row++;

	print_map(map);
	// if (!parse_map(map))
	// 	print_map(map);
	// else
	// 	free(map.content);

	return (0);
}
