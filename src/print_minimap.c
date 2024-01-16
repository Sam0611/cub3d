/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:07:41 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/11 20:17:19 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define BLOCK_SIZE 10

// default color = black
unsigned int	get_color(int color_code)
{
	unsigned int	color;

	color = 255;
	if (color_code == WHITE)
		color = 255 << 24 | 255 << 16 | 255 << 8 | 255;
	if (color_code == RED)
		color = 255 << 24 | 0 << 16 | 0 << 8 | 255;
	return (color);
}

// x is horizontal coordinates, y is vertical coordinates
static void	ft_put_pixel(mlx_image_t *image,
		unsigned int x, unsigned int y, unsigned int color)
{
	unsigned int	initial_x;
	unsigned int	initial_y;

	initial_x = x;
	initial_y = y;
	while (x < BLOCK_SIZE + initial_x && x < MAP_SIZE)
	{
		y = initial_y;
		while (y < BLOCK_SIZE + initial_y && y < MAP_SIZE)
		{
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		x++;
	}
}

static void	draw_map_background(mlx_image_t *image)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			mlx_put_pixel(image, x, y, get_color(BLACK));
			y++;
		}
		x++;
	}
}

static void	init_params(int dist, int player_pos,
		int *i, unsigned int *pixel_pos)
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

void	print_minimap(t_game *game)
{
	int				i;
	int				j;
	unsigned int	pos[2];
	int				distance;

	draw_map_background(game->image);
	distance = (MAP_SIZE - BLOCK_SIZE) / 2 / BLOCK_SIZE;
	init_params(distance, game->player.y, &i, pos + 1);
	while (game->map.content[i])
	{
		init_params(distance, game->player.x, &j, pos);
		while (j < (int)ft_strlen(game->map.content[i]))
		{
			if (i == (int)game->player.y && j == (int)game->player.x)
				ft_put_pixel(game->image, pos[0], pos[1], get_color(RED));
			else if (game->map.content[i][j] == '0')
				ft_put_pixel(game->image, pos[0], pos[1], get_color(WHITE));
			else if (game->map.content[i][j] == '1')
				ft_put_pixel(game->image, pos[0], pos[1], get_color(BLACK));
			j++;
			pos[0] += BLOCK_SIZE;
		}
		i++;
		pos[1] += BLOCK_SIZE;
	}
}
