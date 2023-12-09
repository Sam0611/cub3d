/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:11:12 by smalloir          #+#    #+#             */
/*   Updated: 2023/04/06 18:14:14 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	read_lines(int fd, char **str)
{
	int		size;
	char	*cpy;
	char	*str_cpy;

	size = BUFFER_SIZE;
	cpy = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!cpy)
		return (0);
	cpy[0] = '\0';
	while (size == BUFFER_SIZE)
	{
		size = read(fd, cpy, BUFFER_SIZE);
		if (size < 0)
		{
			free(cpy);
			return (0);
		}
		cpy[size] = '\0';
		str_cpy = *str;
		*str = ft_strjoin(*str, cpy);
		free(str_cpy);
	}
	free(cpy);
	return (1);
}

char	*get_all_lines(int fd)
{
	char	*str;

	str = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_lines(fd, &str))
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	if (!str)
		return (NULL);
	return (str);
}
