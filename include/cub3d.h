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
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	int			dir;
}	t_player;

typedef struct s_wall
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_wall;

typedef struct s_game {
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		*map;
	t_player	player;
}	t_game;

typedef struct s_ray {
	double	cameraX;
	double	dirX;
	double	dirY;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	double	sidedistX;
	double	sidedistY;
	double	deltadistX;
	double	deltadistY;
	double	walldist;
	double	wallX;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

void			print_map(t_map map);
void 			ft_hook(void *param);
void			ft_create_image(t_game *game);
void			set_player_direction(t_player *player);
void			raycasting(t_game game, t_ray *ray, t_wall *wall);
unsigned int	get_color(int color_code);
void			print_view(t_game *game, t_ray ray, t_wall wall);

#endif
