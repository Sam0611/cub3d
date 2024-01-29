/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:42:03 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/19 16:51:37 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#define COMA ','

static int	check_comas(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == COMA)
			count++;
		i++;
	}
	if (count != 2)
	{
		print_error("wrong color parameters");
		return (FAILURE);
	}
	return (SUCCESS);
}

static char	**create_rgb_char_array(char *line)
{
	int		c;
	char	**rgb_tab;

	if (check_comas(line) == FAILURE)
		return (NULL);
	rgb_tab = ft_split(line, ",");
	if (!rgb_tab)
	{
		print_error("memory allocation failed");
		return (NULL);
	}
	c = 0;
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
	int				c;
	int				i;

	i = 0;
	rgb = 0;
	while (rgb_tab[i])
	{
		c = ft_atoi(rgb_tab[i]);
		if (c < 0 || c > 255)
			return (0);
		rgb |= c << (24 - 8 * i);
		i++;
	}
	rgb |= 255;
	return (rgb);
}

static int	check_color_param(char **rgb_tab)
{
	int	i;
	int	j;
	int	is_number;

	i = 0;
	while (rgb_tab[i])
	{
		j = 0;
		while (rgb_tab[i][j] == SPACE)
			j++;
		is_number = ft_isdigit(rgb_tab[i][j]);
		while (ft_isdigit(rgb_tab[i][j]))
			j++;
		while (rgb_tab[i][j] == SPACE)
			j++;
		if (!is_number || rgb_tab[i][j])
		{
			print_error("wrong color parameters");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	init_color(t_texture *tex, char *cur_line, int x)
{
	char	**rgb_tab;

	if ((cur_line[x] == 'C' || cur_line[x] == 'F')
		&& (cur_line[x + 1] == ' ' || cur_line[x + 1] == 9))
	{
		rgb_tab = create_rgb_char_array(cur_line + x + 1);
		if (!rgb_tab)
			return (FAILURE);
		if (!check_color_param(rgb_tab))
		{
			free_tab(rgb_tab);
			return (FAILURE);
		}
		if (cur_line[x] == 'C')
			tex->ceiling = get_rgb(rgb_tab);
		if (cur_line[x] == 'F')
			tex->floor = get_rgb(rgb_tab);
		free_tab(rgb_tab);
		return (1);
	}
	print_error("Wrong parameters");
	return (FAILURE);
}
