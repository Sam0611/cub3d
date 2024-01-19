/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:31:21 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/08 16:31:23 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_data(t_game *game);
void	print_screen_game(t_game game);

static int	check_file(char *map_name)
{
	int	len;
	int	fd;

	len = ft_strlen(map_name) - 4;
	if (len <= 0 || ft_strncmp(map_name + len, ".cub", 5))
	{
		print_error("texture file is not .cub");
		return (0);
	}
	fd = open(map_name, O_DIRECTORY);
	if (fd != -1)
	{
		perror(map_name);
		exit(0);
	}
	fd = open(map_name, O_RDWR, S_IRWXU);
	if (fd < 0)
	{
		perror(map_name);
		exit(0);
	}
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (0);
	if (!check_file(av[1]))
		return (1);
	init_data(&game);
	get_map(av[1], &game);
	if (!game.map.content)
		return (2);
	print_screen_game(game);
	free_tab(game.map.content);
	mlx_delete_texture(game.texture.north);
	mlx_delete_texture(game.texture.south);
	mlx_delete_texture(game.texture.east);
	mlx_delete_texture(game.texture.west);
	return (0);
}
