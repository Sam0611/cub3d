/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:11:12 by smalloir          #+#    #+#             */
/*   Updated: 2022/12/09 03:28:14 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_next_line_read(int fd, char **str)
{
	int		size;
	char	*cpy;
	char	*str_cpy;

	size = BUFFER_SIZE;
	cpy = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!cpy)
		return (0);
	cpy[0] = '\0';
	while (size == BUFFER_SIZE && !ft_findchar('\n', *str))
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

static int	create_line(char **str, char **line, int i)
{
	char	*cpy;

	*line = ft_substr(*str, 0, i + 1);
	cpy = *str;
	*str = ft_substr(*str, i + 1, ft_strlen(*str));
	free(cpy);
	if (!*str || !*line)
		return (0);
	if (ft_strlen(*str) == 0)
	{
		free(*str);
		*str = NULL;
	}
	if (ft_strlen(*line) == 0)
	{
		free(*line);
		*line = NULL;
	}
	return (1);
}

static int	get_next_line_check(int fd, char **str)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!*str)
	{
		*str = ft_strdup("");
		if (!*str)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			i;

	if (!get_next_line_check(fd, &str))
		return (NULL);
	if (!get_next_line_read(fd, &str))
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	if (!str)
		return (NULL);
	i = 0;
	if (ft_strlen(str) > 1)
		while (str[i + 1] && str[i] != '\n')
			i++;
	if (!create_line(&str, &line, i))
		return (NULL);
	return (line);
}
