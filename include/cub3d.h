/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:39:21 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/14 04:51:05 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MLX42/MLX42.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "ft_string.h"
# include "ft_ctype.h"

# define MAP_SIZE 210
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
	char	**f_content;
	char	*name;
	int		col;
	int		row;
	char	p_dir;
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

typedef struct s_tex {
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		*floor;
	int		*ceiling;
}	t_tex;

typedef struct s_game {
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		*map;
	t_player	player;
	t_tex		textures;
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

void			print_map(t_map map, t_game game);
void 			ft_hook(void *param);
void			ft_create_image(t_game *game);
void			set_player_direction(t_player *player);
void			raycasting(t_game game, t_ray *ray);

/*color.c*/
unsigned int	get_color(int color_code);
int				init_color(t_tex *textures, char *cur_line, int x);

/*print_view.c*/
void			print_view(t_game *game, t_ray ray);

/*parsing.c*/
void			get_map(char *filename, t_map *map, t_game *game);

/*create_map.c*/
int				get_map_content(t_map *map, int y);
int				get_file_content(t_map *map);

/*init.c*/
void			initialize(t_game *game, t_map *map);

/*get_texture.c*/
int				get_texture_direction(t_tex *textures, char *cur_line);

/*read_file.c*/
int				read_file(t_map *map, t_game *game);

/*check_outline.c*/
int				check_outline(t_map *map);

/*utils.c*/
int				is_whitespace(char c);
int				ft_isprint(int c);
int				ft_isdigit(int c); //Temporary
void			free_tab(char **tab);

int				print_error(char *str);


#endif
