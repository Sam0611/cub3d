/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:42:03 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/14 05:47:13 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

// default color = black
unsigned int	get_color(int color_code)
{
	unsigned int	color;

	color = 0 << 24 | 0 << 16 | 0 << 8 | 255;
	if (color_code == WHITE)
		color = 255 << 24 | 255 << 16 | 255 << 8 | 255;
	if (color_code == GREY)
		color = 100 << 24 | 100 << 16 | 100 << 8 | 100;
	if (color_code == YELLOW)
		color = 255 << 24 | 243 << 16 | 0 << 8 | 255;
	if (color_code == RED)
		color = 255 << 24 | 0 << 16 | 0 << 8 | 255;
	if (color_code == GREEN)
		color = 183 << 24 | 236 << 16 | 107 << 8 | 255;
	if (color_code == BLUE)
		color = 98 << 24 | 191 << 16 | 255 << 8 | 255;
	return (color);
}

static int	*create_rgb_int_array(int *rgb, char **rgb_tab)
{
	int	i;

	i = 0;
	while (rgb_tab[i])
	{
		rgb[i] = ft_atoi(rgb_tab[i]);
		i++;
	}
	return (rgb);
}

static char	**create_rgb_char_array(char *line)
{
	int		c;
	char	**rgb_tab;

	c = 0;
	rgb_tab = ft_split(line, ',');
	if (!rgb_tab)
		return (NULL);
	while (rgb_tab[c])
		c++;
	if (c != 3)
	{
		free_tab(rgb_tab);
		return (NULL);
	}
	return (rgb_tab);
}

static int	*get_rgb(char *cur_line)
{
	char	**rgb_tab;
	int		*rgb;

	rgb_tab = create_rgb_char_array(cur_line);
	if (!rgb_tab)
		return (0);
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		return (0);
	rgb = create_rgb_int_array(rgb, rgb_tab);
	free_tab(rgb_tab);
	return (rgb);
}

int	init_color(t_tex *textures, char *cur_line, int x)
{
	if (!textures->ceiling && cur_line[x] == 'C')
	{
		textures->ceiling = get_rgb(cur_line + x + 1);
		if (textures->ceiling == 0)
			return (0);
	}
	else if (!textures->floor && cur_line[x] == 'F')
	{
		textures->floor = get_rgb(cur_line + x + 1);
		if (textures->floor == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}
