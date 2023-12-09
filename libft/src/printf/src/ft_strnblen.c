/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnblen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:58:06 by smalloir          #+#    #+#             */
/*   Updated: 2022/11/01 20:13:27 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_slen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_nblen(long long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_nblenbase(long long nb, int base)
{
	int					len;
	unsigned long long	nbr;
	unsigned int		bs;

	len = 1;
	nbr = (unsigned long long)nb;
	bs = (unsigned int)base;
	while (nbr >= bs)
	{
		nbr /= bs;
		len++;
	}
	return (len);
}
