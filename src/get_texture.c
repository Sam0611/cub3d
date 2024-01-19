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

static int	get_texture(char **s_line, mlx_texture_t **tex_data)
{
	int	c;

	c = 0;
	while (s_line[c])
		c++;
	if (c != 2)
		return (print_error("Wrong texture path"));
	*tex_data = mlx_load_png(s_line[1]);
	if (!*tex_data)
		return (0);
	if (tex_data[0]->width != TEX_SIZE || tex_data[0]->height != TEX_SIZE)
		return (print_error("Wrong image size, must be 256x256"));
	return (1);
}

int	get_texture_infos(t_texture *tex, char *cur_line)
{
	char	**line_split;

	line_split = ft_split(cur_line, ' ');
	if (!line_split)
		return (0);
	if (ft_strncmp(line_split[0], "EA", 3) == 0)
		return (get_texture(line_split, &tex->east));
	else if (ft_strncmp(line_split[0], "WE", 3) == 0)
		return (get_texture(line_split, &tex->west));
	else if (ft_strncmp(line_split[0], "NO", 3) == 0)
		return (get_texture(line_split, &tex->north));
	else if (ft_strncmp(line_split[0], "SO", 3) == 0)
		return (get_texture(line_split, &tex->south));
	free_tab(line_split);
	return (0);
}
