/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:12:41 by smalloir          #+#    #+#             */
/*   Updated: 2022/10/21 00:52:26 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	dest2 = dest;
	src2 = (char *)src;
	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			dest2[n] = src2[n];
		}
	}
	else
		ft_memcpy(dest2, src2, n);
	return (dest);
}
