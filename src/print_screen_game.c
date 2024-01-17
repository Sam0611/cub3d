/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:07:41 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/11 20:15:33 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// valgrind + norminette
// error msg

#include "cub3d.h"

void		game_run(void *param);

static void	set_player_direction(t_player *player)
{
	if (player->dir == 'N')
	{
		player->dir_y = -1;
		player->plane_x = 0.66;
	}
	if (player->dir == 'S')
	{
		player->dir_y = 1;
		player->plane_x = -0.66;
	}
	if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->plane_y = 0.66;
	}
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->plane_y = -0.66;
	}
}

static void	get_player_coordinates(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map->content[i])
	{
		j = ft_strsearch_chars(map->content[i], "NSWE");
		if (map->content[i][j])
			break ;
		i++;
	}
	player->y = i;
	player->x = j;
	player->dir = map->content[i][j];
	map->content[i][j] = '0';
}

int	init_window(t_game *game)
{
	mlx_image_t		*image;

	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game->mlx)
		return (1);
	image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!image || mlx_image_to_window(game->mlx, image, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		print_error("Failed to print game screen");
		return (1);
	}
	game->image = image;
	return (0);
}

void	print_screen_game(t_game game)
{
	if (init_window(&game))
		return ;
	get_player_coordinates(&game.map, &game.player);
	set_player_direction(&game.player);
	mlx_loop_hook(game.mlx, game_run, &game);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.image);
	mlx_terminate(game.mlx);
}
