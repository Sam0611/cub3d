/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:31:21 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/08 16:31:23 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <stdbool.h>

void ft_create_image(mlx_image_t *image)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	color;

	color = 255 << 24 | 0 << 16 | 0 << 8 | 255;
	i = 0;
	while (i < image->width)
	{
		j = 0;
		while (j < image->height)
		{
			if (i == IMG_SIZE / 2 || j == IMG_SIZE / 2)
				mlx_put_pixel(image, i, j, color);
			j++;
		}
		i++;
	}
}

void ft_hook(void *param)
{
	t_game	*game;
	
	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) && game->image->instances[0].y)
		game->image->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) && game->image->instances[0].y < HEIGHT - IMG_SIZE)
		game->image->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) && game->image->instances[0].x)
		game->image->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) && game->image->instances[0].x < WIDTH - IMG_SIZE)
		game->image->instances[0].x += 5;
}


int	main()
{
	t_game		game;
	mlx_image_t	*image;

	game.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game.mlx)
		return(1);
	image = mlx_new_image(game.mlx, IMG_SIZE, IMG_SIZE);
	if (!image)
	{
		mlx_close_window(game.mlx);
		return(1);
	}
	game.image = image;
	if (mlx_image_to_window(game.mlx, game.image, 0, 0) == -1)
	{
		mlx_close_window(game.mlx);
		return(1);
	}
	ft_create_image(game.image);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);
}
