/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:16:19 by smalloir          #+#    #+#             */
/*   Updated: 2022/10/19 14:15:01 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		tab = malloc(0);
		return (tab);
	}
	i = nmemb * size;
	if (i / nmemb != size)
		return (0);
	tab = malloc(nmemb * size);
	if (!tab)
		return (0);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
