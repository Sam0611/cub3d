/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b1_wp_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:07:18 by smalloir          #+#    #+#             */
/*   Updated: 2022/11/19 13:42:14 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	b1_wp_s2(int *count, int *tab)
{
	if (tab[3] < tab[2])
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

void	b1_wp_s(char *fmt, va_list ap, int *count, int *tab)
{
	char	*str;
	va_list	vl;

	va_copy(vl, ap);
	str = va_arg(vl, char *);
	if (fmt[tab[0]] == '-')
		b1flags(fmt, ap, count, tab[4]);
	if (str == NULL && tab[2] < 6)
	{
		while (tab[1] > 0)
		{
			*count += write(1, " ", 1);
			tab[1]--;
		}
	}
	else
		b1_wp_s2(count, tab);
	if (fmt[tab[0]] != '-')
		b1flags(fmt, ap, count, tab[4]);
	va_end(vl);
}

static void	b1_wp_p3(int n, int *count, int *tab)
{
	if (tab[2] > tab[3] - 2)
	{
		while (n > 0)
		{
			*count += write(1, " ", 1);
			n--;
		}
	}
	else
	{
		while (tab[1] > tab[3])
		{
			*count += write(1, " ", 1);
			tab[1]--;
		}
	}
}

static void	b1_wp_p2(unsigned long long u, int *count, int *tab)
{
	if (u == 0)
		*count += write(1, "(nil)", 5);
	else
	{
		*count += write(1, "0x", 2);
		while (tab[2] > tab[3] - 2)
		{
			*count += write(1, "0", 1);
			tab[3]++;
		}
		*count += ft_putnbr_base(u, "0123456789abcdef");
	}
}

void	b1_wp_p(char *fmt, va_list ap, int *count, int *tab)
{
	unsigned long long	u;
	va_list				vl;
	int					n;

	va_copy(vl, ap);
	u = va_arg(vl, unsigned long long);
	n = tab[1] - tab[2] - 2;
	if (fmt[tab[0]] == '-')
		b1_wp_p2(u, count, tab);
	if (tab[1] > tab[3])
		b1_wp_p3(n, count, tab);
	if (fmt[tab[0]] != '-')
		b1_wp_p2(u, count, tab);
	va_end(vl);
}
