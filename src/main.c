/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:31:21 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/25 18:13:25 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define FILE_EXTENSION 4

int		init_data(t_game *game);
void	print_screen_game(t_game game);

static int	check_file(char *map_name)
{
	int	len;
	int	fd;

	len = ft_strlen(map_name) - FILE_EXTENSION;
	if (len <= 0 || ft_strncmp(map_name + len, ".cub", 5))
	{
		print_error("texture file is not .cub");
		return (FAILURE);
	}
	fd = open(map_name, O_DIRECTORY);
	if (fd != -1)
	{
		perror(map_name);
		return (FAILURE);
	}
	fd = open(map_name, O_RDWR, S_IRWXU);
	if (fd < 0)
	{
		perror(map_name);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		print_error("map is needed: ./cub3d map/map.cub");
		return (1);
	}
	if (!check_file(av[1]))
		return (2);
	init_data(&game);
	get_map(av[1], &game);
	if (!game.map.content)
		return (3);
	print_screen_game(game);
	free_tab(game.map.content);
	mlx_delete_texture(game.texture.north);
	mlx_delete_texture(game.texture.south);
	mlx_delete_texture(game.texture.east);
	mlx_delete_texture(game.texture.west);
	return (0);
}
