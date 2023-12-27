/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:36:19 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/27 03:37:49 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hook(void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = param;
	x = game->player.x;
	y = game->player.y;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& game->map->content[y - 1][x] != '1')
		game->player.y--;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& game->map->content[y + 1][x] != '1')
		game->player.y++;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& game->map->content[y][x - 1] != '1')
		game->player.x--;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		&& game->map->content[y][x + 1] != '1')
		game->player.x++;
	// if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	// if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	ft_create_image(game);
}
