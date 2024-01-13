/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:39:21 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/11 19:52:25 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <MLX42/MLX42.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "ft_string.h"

# define MAP_SIZE 210
# define WALL_SIZE 60
# define WIDTH 1500
# define HEIGHT 1000

enum e_color
{
	WHITE,
	BLACK,
	GREY,
	YELLOW,
	RED,
	GREEN,
	BLUE
};

typedef struct s_map {
	char	**content;
	char	*name;
	int		row;
}	t_map;

typedef struct s_player {
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			dir;
}	t_player;

typedef struct s_texture
{
	int				x;
	int				y;
	int				height;
	int				width;
	double			pos;
	double			step;
	mlx_texture_t	*data;
	mlx_image_t		*img;
}	t_texture;

typedef struct s_ray {
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	walldist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_game {
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		*map;
	t_player	*player;
	t_ray		*ray;
	t_texture	*texture;
}	t_game;

void			print_map(t_game game);
unsigned int	get_color(int color_code);

#endif
