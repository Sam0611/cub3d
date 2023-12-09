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
#include <math.h>
#include <MLX42/MLX42.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "ft_string.h"

# define IMG_SIZE 30
# define WIDTH 600
# define HEIGHT 600

typedef struct s_game {
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_game;

#endif
