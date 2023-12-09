/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:46:15 by smalloir          #+#    #+#             */
/*   Updated: 2022/07/28 16:47:49 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (dst == 0 && size == 0)
		return (0);
	i = ft_strlen(dst);
	j = ft_strlen(src);
	k = 0;
	if (size > i)
	{
		while (src[k] && k < size - i - 1)
		{
			dst[i + k] = src[k];
			k++;
		}
		dst[i + k] = '\0';
		return (j + i);
	}
	else
		return (size + j);
}
