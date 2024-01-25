/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_newline_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaucie <sbeaucie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:45:00 by sbeaucie          #+#    #+#             */
/*   Updated: 2024/01/25 19:39:22 by sbeaucie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Function to count number of segments
static int	count_segments(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

// Function to allocate memory and copy a segment to the array
static int	copy_segments(char **array, char *str, int tab_i[2], int end)
{
	int	i;
	int	j;

	i = tab_i[0];
	j = 0;
	array[tab_i[1]] = (char *)malloc((end - tab_i[0] + 1) * sizeof(char));
	if (array[tab_i[1]] == NULL)
		return (0);
	while (i < end)
	{
		array[tab_i[1]][j] = str[i];
		j++;
		i++;
	}
	array[tab_i[1]][j] = '\0';
	return (1);
}

// tab_i[0] = start, tab_i[1] = segment index
static int	fill_array(char **array, char *str)
{
	int	tab_i[2];
	int	i;

	i = 0;
	tab_i[0] = 0;
	tab_i[1] = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (!copy_segments(array, str, tab_i, i))
				return (0);
			tab_i[1]++;
			tab_i[0] = i + 1;
		}
		i++;
	}
	copy_segments(array, str, tab_i, ft_strlen(str));
	array[tab_i[1] + 1] = NULL;
	return (1);
}

// Main function for dividing the chain into segments
char	**split_newline_string(char *str)
{
	int		count;
	int		i;
	char	**array;

	i = 0;
	count = count_segments(str);
	array = (char **)malloc((count + 2) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (!fill_array(array, str))
	{
		while (i <= count)
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (NULL);
	}
	return (array);
}
