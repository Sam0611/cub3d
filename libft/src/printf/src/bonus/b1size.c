/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b1size.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:00:53 by smalloir          #+#    #+#             */
/*   Updated: 2024/01/11 19:21:20 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	b1size(char *fmt, va_list ap, int *count, int i)
{
	int	n;
	int	len;

	n = ft_atoi(fmt + i);
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	len = calculate_len(fmt, ap, i);
	if (len < 0)
		return (i);
	while (n > len)
	{
		*count += write(1, " ", 1);
		n--;
	}
	mdt(fmt[i], ap, count);
	return (i);
}

static void	b1_wp_c(char *fmt, va_list ap, int *count, int *tab)
{
	int		nb;
	va_list	vl;

	va_copy(vl, ap);
	nb = va_arg(vl, int);
	if (fmt[tab[0]] == '-')
		*count += ft_putchar(nb);
	while (tab[1] > tab[3])
	{
		*count += write(1, " ", 1);
		tab[1]--;
	}
	if (fmt[tab[0]] != '-')
		*count += ft_putchar(nb);
	va_end(vl);
}

static void	b1_putspaces(int *count, int *tab)
{
	if (tab[3] > tab[2])
	{
		while (tab[1] > tab[3])
		{
			*count += write(1, " ", 1);
			tab[1]--;
		}
	}
	else
	{
		while (tab[1] > tab[2])
		{
			*count += write(1, " ", 1);
			tab[1]--;
		}
	}
}

static void	b1_wp_diux(char *fmt, va_list ap, int *count, int *tab)
{
	int		nb;
	va_list	vl;

	va_copy(vl, ap);
	nb = 1;
	if (ft_findchar(fmt[tab[5]], "di"))
	{
		nb = va_arg(vl, int);
		if (nb < 0)
			tab[2]++;
	}
	else if (ft_findchar(fmt[tab[5]], "uxX"))
		nb = va_arg(vl, unsigned int);
	if (nb == 0 && tab[2] == 0)
		tab[3] = 0;
	if (fmt[tab[0]] == '-')
		b1flags(fmt, ap, count, tab[4]);
	b1_putspaces(count, tab);
	if (fmt[tab[0]] != '-')
		b1flags(fmt, ap, count, tab[4]);
	va_end(vl);
}

int	b1_wp(char *fmt, va_list ap, int *count, int i)
{
	int	tab[6];

	tab[0] = i;
	while (fmt[i] == '-')
		i++;
	tab[1] = ft_atoi(fmt + i);
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	tab[4] = i;
	i++;
	tab[2] = ft_atoi(fmt + i);
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	tab[5] = i;
	tab[3] = calculate_len(fmt, ap, i);
	if (fmt[i] == 'c')
		b1_wp_c(fmt, ap, count, tab);
	else if (fmt[i] == 's')
		b1_wp_s(fmt, ap, count, tab);
	else if (fmt[i] == 'p')
		b1_wp_p(fmt, ap, count, tab);
	else if (ft_findchar(fmt[i], "diuxX"))
		b1_wp_diux(fmt, ap, count, tab);
	return (i);
}
