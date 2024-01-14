/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:16:44 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/13 04:16:44 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture(char **s_line, char **texture)
{
	int	c;
	int	fd;

	c = 0;
	while (s_line[c])
		c++;
	if (c != 2)
		return (0); //err, incorect line
	fd = open(s_line[1], O_RDONLY);
	if (fd == -1)
		return (0); //err
	close(fd);
	*texture = ft_strdup(s_line[1]);
	if (!texture)
		return (print_error("failed to allocate memory"));
	free_tab(s_line);
	return (1);
}

int	get_texture_direction(t_tex *textures, char *cur_line)
{
	char	**line_split;

	line_split = ft_split(cur_line, ' ');
	if (!line_split)
		return (0);
	if (ft_strncmp(line_split[0], "EA", 3) == 0)
		return (get_texture(line_split, &textures->east));
	else if (ft_strncmp(line_split[0], "WE", 3) == 0)
		return (get_texture(line_split, &textures->west));
	else if (ft_strncmp(line_split[0], "NO", 3) == 0)
		return (get_texture(line_split, &textures->north));
	else if (ft_strncmp(line_split[0], "SO", 3) == 0)
		return (get_texture(line_split, &textures->south));
	free_tab(line_split);
	return (0);
}
