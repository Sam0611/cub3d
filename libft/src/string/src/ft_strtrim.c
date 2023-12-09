/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:53:16 by smalloir          #+#    #+#             */
/*   Updated: 2022/10/18 19:16:50 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int	nb_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] && s1[i])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

static int	nb_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i--;
			j = -1;
		}
		j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*ret;

	if (!s1 || !set)
		return (0);
	start = nb_start(s1, set);
	if (!s1[start])
	{
		ret = malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	end = nb_end(s1, set);
	len = end - start + 1;
	ret = ft_substr(s1, start, len);
	return (ret);
}
