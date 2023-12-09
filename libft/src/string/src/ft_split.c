/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:51:16 by smalloir          #+#    #+#             */
/*   Updated: 2022/09/26 14:51:18 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**ft_strfill(char **str, char const *s, char c, int nb)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j < nb)
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			str[j][k] = s[i];
			i++;
			k++;
		}
		str[j][k] = '\0';
		j++;
	}
	str[j] = NULL;
	return (str);
}

static void	ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static char	**str_alloc(char const *s, char c, char **str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
		{
			str[k] = malloc((i - j + 1) * sizeof(char));
			if (!str[k])
			{
				ft_free(str, k);
				return (NULL);
			}
		}
		k++;
	}
	return (str);
}

static int	nb_words(char const *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			n++;
		while (s[i] != c && s[i])
			i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		nb;

	if (!s)
		return (0);
	nb = nb_words(s, c);
	str = (char **)malloc((nb + 1) * sizeof(char *));
	if (!str)
		return (0);
	str = str_alloc(s, c, str);
	if (str)
		str = ft_strfill(str, s, c, nb);
	return (str);
}
