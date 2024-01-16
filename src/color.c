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

// default color = black
unsigned int	get_color(int color_code)
{
	unsigned int	color;

	color = 255;
	if (color_code == WHITE)
		color = 255 << 24 | 255 << 16 | 255 << 8 | 255;
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

static char	**create_rgb_char_array(char *line)
{
	int		c;
	char	**rgb_tab;

	c = 0;
	rgb_tab = ft_split(line, ',');
	if (!rgb_tab)
	{
		print_error("memory allocation failed");
		return (NULL);
	}
	while (rgb_tab[c])
		c++;
	if (c != 3)
	{
		free_tab(rgb_tab);
		print_error("wrong number of color parameter");
		return (NULL);
	}
	return (rgb_tab);
}

static unsigned int	get_rgb(char **rgb_tab)
{
	unsigned int	rgb;

	rgb = ft_atoi(rgb_tab[0]) << 24;
	rgb |= ft_atoi(rgb_tab[1]) << 16;
	rgb |= ft_atoi(rgb_tab[2]) << 8;
	rgb |= 255;
	return (rgb);
}

static int	check_color_param(char **rgb_tab)
{
	int	i;
	int	j;

	i = 0;
	while (rgb_tab[i])
	{
		j = 0;
		while (rgb_tab[i][j])
		{
			if (!ft_isdigit(rgb_tab[i][j]))
				return (print_error("wrong color parameters"));
			j++;
		}
		i++;
	}
	return (1);
}

int	init_color(t_tex *textures, char *cur_line, int x)
{
	char	**rgb_tab;

	if ((cur_line[x] == 'C' || cur_line[x] == 'F') && cur_line[x + 1] == ' ')
	{
		rgb_tab = create_rgb_char_array(cur_line + 2);
		if (!rgb_tab || !check_color_param(rgb_tab))
			return (0);
		if (cur_line[x] == 'C')
			textures->ceiling = get_rgb(rgb_tab);
		if (cur_line[x] == 'F')
			textures->floor = get_rgb(rgb_tab);
		free_tab(rgb_tab);
		return (1);
	}
	return (0);
}
