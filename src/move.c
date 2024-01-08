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

#define SPEED 0.2

void	ft_hook(void *param)
{
	t_game	*game;
	double		x;
	double		y;

	game = param;
	x = game->player.x;
	y = game->player.y;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		x += game->player.dirX * SPEED;
		y += game->player.dirY * SPEED;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		x -= game->player.dirX * SPEED;
		y -= game->player.dirY * SPEED;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		x += game->player.dirY * SPEED;
		y -= game->player.dirX * SPEED;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		x -= game->player.dirY * SPEED;
		y += game->player.dirX * SPEED;
	}
	if (game->map->content[(int)y][(int)x] != '1')
	{
		game->player.x = x;
		game->player.y = y;
	}
	
	double rotSpeed = 0.1;
	double oldDirX = game->player.dirX;
	double oldPlaneX = game->player.planeX;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
      game->player.dirX = game->player.dirX * cos(rotSpeed) - game->player.dirY * sin(rotSpeed);
      game->player.dirY = oldDirX * sin(rotSpeed) + game->player.dirY * cos(rotSpeed);
      game->player.planeX = game->player.planeX * cos(rotSpeed) - game->player.planeY * sin(rotSpeed);
      game->player.planeY = oldPlaneX * sin(rotSpeed) + game->player.planeY * cos(rotSpeed);
    }
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
      game->player.dirX = game->player.dirX * cos(-rotSpeed) - game->player.dirY * sin(-rotSpeed);
      game->player.dirY = oldDirX * sin(-rotSpeed) + game->player.dirY * cos(-rotSpeed);
      game->player.planeX = game->player.planeX * cos(-rotSpeed) - game->player.planeY * sin(-rotSpeed);
      game->player.planeY = oldPlaneX * sin(-rotSpeed) + game->player.planeY * cos(-rotSpeed);
    }
	raycasting(game);
	ft_create_image(game);
}
