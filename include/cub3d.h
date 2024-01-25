/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:39:21 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/23 06:02:18 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <MLX42/MLX42.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"
# include "ft_string.h"
# include "ft_stdlib.h"
# include "ft_ctype.h"

# define MAP_SIZE 210
# define TEX_SIZE 256
# define WIDTH 1500
# define HEIGHT 1000

# define SUCCESS 1
# define FAILURE 0

enum e_color
{
	WHITE,
	BLACK,
	RED
};

typedef struct s_map {
	char	**content;
	char	**f_cont;
	char	*name;
	int		col;
	int		row;
	int		eom;
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

typedef struct s_ray {
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	startdist_x;
	double	startdist_y;
	double	sidedist_x;
	double	sidedist_y;
	double	walldist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_texture
{
	int				x;
	int				y;
	double			pos;
	double			step;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	unsigned int	floor;
	unsigned int	ceiling;
}	t_texture;

typedef struct s_game {
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
}	t_game;

/*color.c*/
int				init_color(t_texture *texture, char *cur_line, int x);

/*print_view.c*/
void			print_view(t_game *game, t_ray ray);

/*parsing.c*/
void			get_map(char *filename, t_game *game);

/*create_map.c*/
int				get_map_content(t_map *map, int y);
int				get_file_content(t_map *map);

/*init.c*/
void			initialize(t_game *game, t_map *map);

/*get_texture.c*/
int				get_texture_infos(t_texture *texture, char *cur_line);

/*read_file.c*/
int				read_file(t_map *map, t_game *game);

/*check_outline.c*/
int				check_outline(t_map *map);

/*utils.c*/
int				is_whitespace(char c);
int				ft_isdigit(int c); //Temporary
void			free_tab(char **tab);

int				print_error(char *str);
#endif
