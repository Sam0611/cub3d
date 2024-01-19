/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:17:09 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/19 16:17:52 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_row(char **f_content, int y)
{
	int			x;
	int			first_row;
	static char	*whitespace = " \t\r\v\f";

	first_row = y;
	while (f_content[y])
	{
		x = 0;
		while (f_content[y][x] && ft_strchr(whitespace, f_content[y][x]))
			x++;
		if (f_content[y][x] != '1')
			break ;
		y++;
	}
	return (y - first_row);
}

int	count_col(char **f_content, int y)
{
	int	res;
	int	line_size;

	res = ft_strlen(f_content[y]);
	while (f_content[y])
	{
		line_size = ft_strlen(f_content[y]);
		if (res < line_size)
			res = line_size;
		y++;
	}
	return (res);
}
