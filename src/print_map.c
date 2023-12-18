/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:07:41 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/10 14:07:43 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define WHITE 1
#define BLACK 2
#define RED 3
#define BLOCK_SIZE 30

// default color = black
unsigned int    get_color(int color_code)
{
    unsigned int    color;

    color = 0 << 24 | 0 << 16 | 0 << 8 | 255;
    if (color_code == WHITE)
        color = 255 << 24 | 255 << 16 | 255 << 8 | 255;
    if (color_code == RED)
        color = 255 << 24 | 0 << 16 | 0 << 8 | 255;
    return (color);
}

// x is horizontal coordinates, y is vertical coordinates
void    ft_put_pixel(mlx_image_t *image, unsigned int x, unsigned int y, unsigned int color)
{
    unsigned int initial_x;
    unsigned int initial_y;

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

void ft_create_image(t_game *game)
{
    int i = 0;
    while (game->map->content[i])
    {
        printf("%s\n", game->map->content[i]);
        i++;
    }

	// unsigned int	i;
	// unsigned int	pos[2];
    // int             distance[3];

    // distance[0] = 0;
    // distance[1] = 0;
    // distance[2] = (IMG_SIZE - BLOCK_SIZE) / 2 / BLOCK_SIZE;
    // if (distance[2] >= game->player.x)
    // {
    //     distance[0] = BLOCK_SIZE * (distance[2] - game->player.x + 1);
    //     distance[2] = game->player.x - 1;
    // }
    // i = game->player.pos - distance[2];
    // pos[0] = distance[0];
    // pos[1] = distance[1];
    // while (game->map->content[i])
    // {
    //     if (game->map->content[i] == '0')
    //         ft_put_pixel(game->image, pos[0], pos[1], get_color(WHITE));
    //     else if (game->map->content[i] == '1')
    //         ft_put_pixel(game->image, pos[0], pos[1], get_color(BLACK));
    //     else
    //         ft_put_pixel(game->image, pos[0], pos[1], get_color(RED));
    //     pos[0] += BLOCK_SIZE;
    //     i++;
    //     if (game->map->content[i] == '\n')
    //     {
    //         pos[1] += BLOCK_SIZE;
    //         pos[0] = distance[0];
    //         i += game->player.x - distance[2];
    //     }
    // }

    // if (i == IMG_SIZE / 2 || j == IMG_SIZE / 2)
    // 	mlx_put_pixel(game->image, i, j, get_color(RED));
    // else
    // 	mlx_put_pixel(game->image, i, j, get_color(WHITE));
}

void    get_player_coordinates(t_map map, t_player *player)
{
    int i;

    i = 0;
    while (map.content[i])
    {
        player->x = ft_strsearch_chars(map.content[i], "NSWE");
        if (map.content[player->x])
            break ;
        i++;
    }
    player->y = i;
}
    
void    print_map(t_map map)
{
	t_game		game;
    t_player    player;
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