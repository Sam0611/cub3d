/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:39:21 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/08 16:49:19 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MLX42/MLX42.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "ft_string.h"

# define IMG_SIZE 210
# define WIDTH 1500
# define HEIGHT 1000

typedef struct s_map {
	char	**content;
	char	*name;
	int		row;
}	t_map;

typedef struct s_player {
	float		x;
	float		y;
}	t_player;

typedef struct s_game {
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		*map;
	t_player	player;
}	t_game;

void    print_map(t_map map);
void 	ft_hook(void *param);
void	ft_create_image(t_game *game);

#endif
