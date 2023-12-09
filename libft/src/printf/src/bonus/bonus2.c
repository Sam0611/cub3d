/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:24:15 by smalloir          #+#    #+#             */
/*   Updated: 2022/11/06 00:14:33 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	bonus2a(char *fmt, va_list ap, int *count, int i)
{
	unsigned int	u;

	if (fmt[i] == '#' && (fmt[i + 1] == 'x' || fmt[i + 1] == 'X'))
	{
		u = va_arg(ap, unsigned int);
		*count += write(1, "0", 1);
		if (u != 0)
		{
			if (fmt[i + 1] == 'x')
			{
				*count += write(1, "x", 1);
				*count += ft_putnbr_base(u, "0123456789abcdef");
			}
			else
			{
				*count += write(1, "X", 1);
				*count += ft_putnbr_base(u, "0123456789ABCDEF");
			}
		}
	}
}

void	bonus2(char *fmt, va_list ap, int *count, int i)
{
	int	u;

	if ((fmt[i] == '+' || fmt[i] == ' ')
		&& (fmt[i + 1] == 'd' || fmt[i + 1] == 'i'))
	{
		u = va_arg(ap, int);
		if (u >= 0)
		{
			if (fmt[i] == '+')
				*count += write(1, "+", 1);
			else
				*count += write(1, " ", 1);
		}
		ft_putnbr(u);
		*count += ft_nblen(u);
	}
	else
		bonus2a(fmt, ap, count, i);
}
