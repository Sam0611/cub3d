/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:07:41 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/27 03:41:34 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// perso rond au lieu de carré
// raycasting
// 3D

#include "cub3d.h"

#define WHITE 1
#define BLACK 2
#define RED 3
#define GREY 4
#define BLOCK_SIZE 10
#define NOT_FOUND 4

// default color = black
unsigned int	get_color(int color_code)
{
	unsigned int	color;

	color = 0 << 24 | 0 << 16 | 0 << 8 | 255;
	if (color_code == WHITE)
		color = 255 << 24 | 255 << 16 | 255 << 8 | 255;
	if (color_code == GREY)
		color = 100 << 24 | 100 << 16 | 100 << 8 | 100;
	if (color_code == RED)
		color = 255 << 24 | 0 << 16 | 0 << 8 | 255;
	return (color);
}

// x is horizontal coordinates, y is vertical coordinates
void	ft_put_pixel(mlx_image_t *image,
		unsigned int x, unsigned int y, unsigned int color)
{
	unsigned int	initial_x;
	unsigned int	initial_y;

	initial_x = x;
	initial_y = y;
	while (x < BLOCK_SIZE + initial_x && x < image->width)
	{
		y = initial_y;
		while (y < BLOCK_SIZE + initial_y && y < image->height)
		{
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_map_background(mlx_image_t *image)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			mlx_put_pixel(image, x, y, get_color(GREY));
			y++;
		}
		x++;
	}
}

void	init_params(int dist, int player_pos, int *i, unsigned int *pixel_pos)
{
	if (dist <= player_pos)
	{
		*i = player_pos - dist;
		*pixel_pos = 0;
	}
	else
	{
		*i = 0;
		*pixel_pos = (dist - player_pos) * BLOCK_SIZE;
	}
}

void	ft_create_image(t_game *game)
{
	int				i;
	int				j;
	unsigned int	pos[2];
	int				distance;

	draw_map_background(game->image);
	distance = (IMG_SIZE - BLOCK_SIZE) / 2 / BLOCK_SIZE;
	init_params(distance, game->player.y, &i, pos + 1);
	while (game->map->content[i])
	{
		init_params(distance, game->player.x, &j, pos);
		while (j < (int)ft_strlen(game->map->content[i]))
		{
			if (i == game->player.y && j == game->player.x)
				ft_put_pixel(game->image, pos[0], pos[1], get_color(RED));
			else if (game->map->content[i][j] == '0')
				ft_put_pixel(game->image, pos[0], pos[1], get_color(WHITE));
			else if (game->map->content[i][j] == '1')
				ft_put_pixel(game->image, pos[0], pos[1], get_color(BLACK));
			j++;
			pos[0] += BLOCK_SIZE;
		}
		i++;
		pos[1] += BLOCK_SIZE;
	}
}

void	get_player_coordinates(t_map map, t_player *player)
{
	int	i;

	i = 0;
	while (map.content[i])
	{
		player->x = ft_strsearch_chars(map.content[i], "NSWE");
		if (map.content[i][player->x])
			break ;
		i++;
	}
	player->y = i;
	map.content[player->y][player->x] = '0';
}

void	print_map(t_map map)
{
	t_game		game;
	t_player	player;
	mlx_image_t	*image;

	get_player_coordinates(map, &player);
	game.player = player;
	game.map = &map;
	game.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game.mlx)
		return ;
	image = mlx_new_image(game.mlx, IMG_SIZE, IMG_SIZE);
	if (!image)
	{
		mlx_close_window(game.mlx);
		return ;
	}
	game.image = image;
	if (mlx_image_to_window(game.mlx, game.image, 0, 0) == -1)
	{
		mlx_close_window(game.mlx);
		return ;
	}
	ft_create_image(&game);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
