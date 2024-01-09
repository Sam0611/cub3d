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

//code propre
//textures
//leaks ?

#include "cub3d.h"

#define BLOCK_SIZE 10
#define NOT_FOUND 4

// x is horizontal coordinates, y is vertical coordinates
void	ft_put_pixel(mlx_image_t *image,
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

void	draw_map_background(mlx_image_t *image)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
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
	distance = (MAP_SIZE - BLOCK_SIZE) / 2 / BLOCK_SIZE;
	init_params(distance, game->player.y, &i, pos + 1);
	while (game->map->content[i])
	{
		init_params(distance, game->player.x, &j, pos);
		while (j < (int)ft_strlen(game->map->content[i]))
		{
			if (i == (int)game->player.y && j == (int)game->player.x)
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
	// mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	get_player_coordinates(t_map map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map.content[i])
	{
		j = ft_strsearch_chars(map.content[i], "NSWE");
		if (map.content[i][j])
			break ;
		i++;
	}
	player->y = i;
	player->x = j;
	player->dir = map.content[i][j];
	map.content[i][j] = '0';
}

void	print_map(t_map map)
{
	t_game		game;
	t_player	player;
	t_ray		ray;
	t_wall		wall;
	mlx_image_t	*image;
	xpm_t		*xpm;

	xpm = mlx_load_xpm42("sonic.xpm42");
	if (!xpm)
		printf("xpm failed\n");
	else
		printf("xpm ok\n");
	// mlx_delete_texture(xpm->texture);
	// mlx_delete_xpm42(xpm);
	get_player_coordinates(map, &player);
	set_player_direction(&player);
	ray.dirX = 0;
	ray.dirY = 0;
	game.player = player;
	game.ray = &ray;
	game.wall = &wall;
	game.map = &map;
	game.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game.mlx)
		return ;
	// game.img = mlx_texture_to_image(game.mlx, &xpm->texture); // texture sonic
	image = mlx_new_image(game.mlx, WIDTH, HEIGHT);
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
