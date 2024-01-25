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

#include "ft_string.h"

static char	*get_word(char *str, char const *s, int end, int len)
{
	str[len] = 0;
	while (len > 0)
	{
		len--;
		end--;
		str[len] = s[end];
	}
	return (str);
}

static char	**alloc_word(char **str, int word, int letter)
{
	str[word] = malloc(sizeof(char) * (letter + 1));
	if (!str[word])
	{
		while (word >= 0)
		{
			free(str[word]);
			word--;
		}
		free(str);
		return (NULL);
	}
	return (str);
}

static char	**split_words(char **str, char const *s, char *charset)
{
	int		i;
	int		word;
	int		letter;

	i = 0;
	word = 0;
	while (s[i])
	{
		letter = 0;
		while (s[i] && ft_findchar(s[i], charset))
			i++;
		if (!s[i])
			break ;
		while (s[i] && !ft_findchar(s[i], charset))
		{
			letter++;
			i++;
		}
		str = alloc_word(str, word, letter);
		if (!str)
			return (NULL);
		str[word] = get_word(str[word], s, i, letter);
		word++;
	}
	return (str);
}

static int	count_words(char const *s, char *charset)
{
	int		i;
	int		j;
	int		n;
	int		word;

	i = 0;
	n = 0;
	word = 0;
	while (s[i])
	{
		j = 0;
		word++;
		while (charset[j])
		{
			if (s[i] == charset[j])
				word = 0;
			j++;
		}
		if (word == 1)
			n++;
		i++;
	}
	return (n);
}

char	**ft_split(char const *s, char *charset)
{
	char	**str;
	int		word;

	if (!s)
		return (NULL);
	word = count_words(s, charset);
	str = malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[word] = NULL;
	str = split_words(str, s, charset);
	return (str);
}
