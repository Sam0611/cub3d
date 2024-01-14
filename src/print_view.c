/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:05:13 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/30 17:05:15 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_view(t_game *game, t_ray ray)
{
	unsigned int	x;
	unsigned int	y;

	(void)ray;
	x = 0;
	while (x < game->image->width)
	{
		y = 0;
		while (y < game->image->height)
		{
			if (y <= game->image->height / 3)
				mlx_put_pixel(game->image, x, y, get_color(BLUE));
			else if (y >= game->image->height / 3 * 2)
				mlx_put_pixel(game->image, x, y, get_color(GREEN));
			else
				mlx_put_pixel(game->image, x, y, get_color(YELLOW));
			y++;
		}
		x++;
	}
	return ;
}
