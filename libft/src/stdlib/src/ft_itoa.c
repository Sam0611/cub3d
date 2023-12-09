/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:50:08 by smalloir          #+#    #+#             */
/*   Updated: 2022/10/19 14:24:43 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*putnb(int n, char *str, int i)
{
	long	nb;

	nb = n;
	str[i] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 9)
	{
		i--;
		str[i] = nb % 10 + '0';
		nb /= 10;
	}
	str[i - 1] = nb + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	i = 1;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str = putnb(n, str, i);
	return (str);
}
