/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:52:39 by smalloir          #+#    #+#             */
/*   Updated: 2022/09/26 14:52:41 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == 0 && len == 0)
		return (0);
	if (!little[0])
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && big[i + j])
			j++;
		if (little[j] == '\0' && i + j <= len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
