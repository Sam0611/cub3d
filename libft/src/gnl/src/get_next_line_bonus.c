/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:11:12 by smalloir          #+#    #+#             */
/*   Updated: 2022/12/11 19:56:51 by smalloir         ###   ########.fr       */
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
	while (size == BUFFER_SIZE && !ft_findchar('\n', str[fd]))
	{
		size = read(fd, cpy, BUFFER_SIZE);
		if (size < 0)
		{
			free(cpy);
			free(str[fd]);
			return (0);
		}
		cpy[size] = '\0';
		str_cpy = str[fd];
		str[fd] = ft_strjoin(str[fd], cpy);
		free(str_cpy);
	}
	free(cpy);
	return (1);
}

static int	create_line(int fd, char **str, char **line, int i)
{
	char	*cpy;

	*line = ft_substr(str[fd], 0, i + 1);
	cpy = str[fd];
	str[fd] = ft_substr(str[fd], i + 1, ft_strlen(str[fd]));
	free(cpy);
	if (!str[fd] || !*line)
		return (0);
	if (ft_strlen(str[fd]) == 0)
	{
		free(str[fd]);
		str[fd] = NULL;
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
	if (!str[fd])
	{
		str[fd] = ft_strdup("");
		if (!str[fd])
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;
	int			i;

	if (!get_next_line_check(fd, str))
		return (NULL);
	if (!get_next_line_read(fd, str))
		return (NULL);
	if (!str[fd])
		return (NULL);
	i = 0;
	if (ft_strlen(str[fd]) > 1)
		while (str[fd][i + 1] && str[fd][i] != '\n')
			i++;
	if (!create_line(fd, str, &line, i))
		return (NULL);
	return (line);
}
