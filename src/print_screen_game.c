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

//textures
// valgrind + norminette
// get color -> minimap (enum)
// map (sumabura.cub, anime.cub, hanzi.cub)
// error msg
// rassembler les structures textures
// suppr .txt .xpm
// makefile fclean
// p_dir = player->dir
// fichier ini.c et ini_data.c

#include "cub3d.h"

t_player	*init_player(void);
t_ray		*init_ray(void);
t_texture	*init_texture(void);
int			init_data(t_game *game);
void		get_player_coordinates(t_map *map, t_player *player);
void		set_player_direction(t_player *player);
void		game_run(void *param);

void	print_screen_game(t_game game)
{
	game.player = init_player();
	game.ray = init_ray();
	game.texture = init_texture();
	if (!game.player || !game.ray || !game.texture || init_data(&game))
		return ;
	get_player_coordinates(game.map, game.player);
	set_player_direction(game.player);
	mlx_loop_hook(game.mlx, game_run, &game);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.image);
	mlx_delete_texture(game.texture->data);
	mlx_terminate(game.mlx);
	free(game.player);
	free(game.ray);
	free(game.texture);
}
