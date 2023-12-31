/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:36:19 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/10 14:36:20 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define PACE 5

void ft_hook(void *param)
{
	t_game	*game;
	
	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)) // MLX_KEY_W
		game->image->instances[0].y += PACE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)) // MLX_KEY_S
		game->image->instances[0].y -= PACE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)) // MLX_KEY_A
		game->image->instances[0].x += PACE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)) // MLX_KEY_D
		game->image->instances[0].x -= PACE;
}
