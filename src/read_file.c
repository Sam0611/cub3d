/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:23:26 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/13 04:23:26 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Fonction pour compter le nombre de segments
int count_segments(char* str)
{
	int count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

// Fonction pour allouer la mémoire et copier un segment dans le tableau
int	copy_segments(char **array, char *str, int seg_i, int start, int end)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	array[seg_i] = (char *)malloc((end - start + 1) * sizeof(char));
	if (array[seg_i] == NULL)
		return (0);
	while (i < end)
	{
		array[seg_i][j] = str[i];
		j++;
		i++;
	}
	array[seg_i][j] = '\0';
	return (1);
}

int	fill_array(char **array, char *str)
{
	int	i;
	int	seg_i;
	int	start;

	start = 0;
	seg_i = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (!copy_segments(array, str, seg_i, start, i))
				return (0);
			seg_i++;
			start = i + 1;
		}
		i++;
	}
	copy_segments(array, str, seg_i, start, strlen(str));
	array[seg_i + 1] = NULL;
	return (1);
}

// Fonction principale pour diviser la chaîne en segments
char	**split_newline_string(char *str)
{
	int		count;
	int		i;
	char	**array;

	i = 0;
	count = count_segments(str);
	array = (char**)malloc((count + 1) * sizeof(char*));
	if (array == NULL)
		return (NULL);
	if (!fill_array(array, str))
	{
		while (i <= count)
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (NULL);
	}
	return (array);
}

#include <stdio.h> // tmp
int	get_file_content(t_map *map)
{
	int			fd;
	char		*tmp;

	fd = open(map->name, O_RDONLY);
	if (fd < 0)
	{
		print_error(strerror(errno));
		return (FAILURE);
	}
	tmp = get_all_lines(fd);
	//map->f_cont = ft_split(tmp, '\n');
	map->f_cont = split_newline_string(tmp);
	int i = 0;
	while (map->f_cont[i])
	{
		printf("%s\n", map->f_cont[i]);
		i++;
	}

	free(tmp);
	close(fd);
	if (!map->f_cont)
	{
		print_error("memory allocation failed");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	is_param(t_map *map, t_game *game, int y, int x)
{
	if (map->f_cont[y][x + 1] && ft_isprint(map->f_cont[y][x + 1]))
	{
		if (!get_texture_infos(&game->texture, map->f_cont[y]))
			return (FAILURE);
	}
	else
	{
		if (!init_color(&game->texture, map->f_cont[y], x))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	read_file(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map->f_cont[y])
	{
		x = 0;
		while (map->f_cont[y][x])
		{
			while (map->f_cont[y][x] && ft_strchr(" \t", map->f_cont[y][x]))
				x++;
			if (!ft_isdigit(map->f_cont[y][x]) && ft_isprint(map->f_cont[y][x]))
			{
				if (!is_param(map, game, y, x))
					return (FAILURE);
				break ;
			}
			else if (ft_isdigit(map->f_cont[y][x]))
				return (get_map_content(map, y));
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
