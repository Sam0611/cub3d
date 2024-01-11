/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:07:41 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/11 20:15:33 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//textures
// valgrind a l'école + header pour init_data.c + norminette

#include "cub3d.h"

t_player	*init_player(void);
t_ray		*init_ray(void);
int			init_data(t_game *game);
void		get_player_coordinates(t_map *map, t_player *player);
void		set_player_direction(t_player *player);
void		game_run(void *param);

// print_game_screen
void	print_map(t_game game)
{
	game.player = init_player();
	game.ray = init_ray();
	if (!game.player || !game.ray || init_data(&game))
		return ;
	get_player_coordinates(game.map, game.player);
	set_player_direction(game.player);
	// mlx_resize_image(game.img, 200, 100);
	// mlx_image_to_window(game.mlx, game.img, 0, 0);
	mlx_loop_hook(game.mlx, game_run, &game);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.image);
	mlx_delete_image(game.mlx, game.img);
	// mlx_close_window(game.mlx);
	mlx_terminate(game.mlx);
	free(game.player);
	free(game.ray);
}
