/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:36:19 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/11 20:11:42 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define SPEED 0.2

void	print_minimap(t_game *game);
void	raycasting(t_game *game);

static void	player_rotate(t_game *game)
{
	double	s;
	double	d;
	double	p;

	s = 0.1;
	d = game->player->dir_x;
	p = game->player->plane_x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->player->dir_x = game->player->dir_x * cos(s)
			- game->player->dir_y * sin(s);
		game->player->dir_y = d * sin(s) + game->player->dir_y * cos(s);
		game->player->plane_x = game->player->plane_x * cos(s)
			- game->player->plane_y * sin(s);
		game->player->plane_y = p * sin(s) + game->player->plane_y * cos(s);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->player->dir_x = game->player->dir_x * cos(-s)
			- game->player->dir_y * sin(-s);
		game->player->dir_y = d * sin(-s) + game->player->dir_y * cos(-s);
		game->player->plane_x = game->player->plane_x * cos(-s)
			- game->player->plane_y * sin(-s);
		game->player->plane_y = p * sin(-s) + game->player->plane_y * cos(-s);
	}
}

static void	player_move(t_game *game, double x, double y)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		x += game->player->dir_x * SPEED;
		y += game->player->dir_y * SPEED;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		x -= game->player->dir_x * SPEED;
		y -= game->player->dir_y * SPEED;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		x += game->player->dir_y * SPEED;
		y -= game->player->dir_x * SPEED;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		x -= game->player->dir_y * SPEED;
		y += game->player->dir_x * SPEED;
	}
	if (game->map->content[(int)y][(int)x] != '1')
	{
		game->player->x = x;
		game->player->y = y;
	}
}

void	game_run(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	player_move(game, game->player->x, game->player->y);
	player_rotate(game);
	raycasting(game);
	print_minimap(game);
}
