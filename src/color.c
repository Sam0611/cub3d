/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:42:03 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/30 16:42:05 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
