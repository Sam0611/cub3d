/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 03:45:26 by smalloir          #+#    #+#             */
/*   Updated: 2022/11/11 03:45:40 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_findstr(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
