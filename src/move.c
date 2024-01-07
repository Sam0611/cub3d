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
	int		x;
	int		y;

	game = param;
	x = game->player.x;
	y = game->player.y;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& game->map->content[y - 1][x] != '1')
		game->player.y -= SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& game->map->content[y + 1][x] != '1')
		game->player.y += SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& game->map->content[y][x - 1] != '1')
		game->player.x -= SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		&& game->map->content[y][x + 1] != '1')
		game->player.x += SPEED;
	raycasting(game);
	double rotSpeed = 0.1;
	double oldDirX = game->ray->dirX;
	double oldPlaneX = game->player.planeX;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
      game->ray->dirX = game->ray->dirX * cos(rotSpeed) - game->ray->dirY * sin(rotSpeed);
      game->ray->dirY = oldDirX * sin(rotSpeed) + game->ray->dirY * cos(rotSpeed);
      game->player.planeX = game->player.planeX * cos(rotSpeed) - game->player.planeY * sin(rotSpeed);
      game->player.planeY = oldPlaneX * sin(rotSpeed) + game->player.planeY * cos(rotSpeed);
    }
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
      game->ray->dirX = game->ray->dirX * cos(-rotSpeed) - game->ray->dirY * sin(-rotSpeed);
      game->ray->dirY = oldDirX * sin(-rotSpeed) + game->ray->dirY * cos(-rotSpeed);
      game->player.planeX = game->player.planeX * cos(-rotSpeed) - game->player.planeY * sin(-rotSpeed);
      game->player.planeY = oldPlaneX * sin(-rotSpeed) + game->player.planeY * cos(-rotSpeed);
    }
	ft_create_image(game);
}
