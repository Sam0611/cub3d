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

static void	player_rotate(t_game *game, t_player *player)
{
	double	s;
	double	d;
	double	p;

	s = 0.1;
	d = player->dir_x;
	p = player->plane_x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		player->dir_x = player->dir_x * cos(s) - player->dir_y * sin(s);
		player->dir_y = d * sin(s) + player->dir_y * cos(s);
		player->plane_x = player->plane_x * cos(s) - player->plane_y * sin(s);
		player->plane_y = p * sin(s) + player->plane_y * cos(s);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		player->dir_x = player->dir_x * cos(-s) - player->dir_y * sin(-s);
		player->dir_y = d * sin(-s) + player->dir_y * cos(-s);
		player->plane_x = player->plane_x * cos(-s) - player->plane_y * sin(-s);
		player->plane_y = p * sin(-s) + player->plane_y * cos(-s);
	}
}

static void	player_move(t_game *game, t_player *player, double x, double y)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		x += player->dir_x * SPEED;
		y += player->dir_y * SPEED;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		x -= player->dir_x * SPEED;
		y -= player->dir_y * SPEED;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		x += player->dir_y * SPEED;
		y -= player->dir_x * SPEED;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		x -= player->dir_y * SPEED;
		y += player->dir_x * SPEED;
	}
	if (game->map.content[(int)y][(int)x] != '1')
	{
		player->x = x;
		player->y = y;
	}
}

void	game_run(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	player_move(game, &game->player, game->player.x, game->player.y);
	player_rotate(game, &game->player);
	raycasting(game);
	print_minimap(game);
}
