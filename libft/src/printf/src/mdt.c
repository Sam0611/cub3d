/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 03:30:03 by smalloir          #+#    #+#             */
/*   Updated: 2022/11/05 03:30:20 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	mdt2(char c, va_list ap, int *count)
{
	unsigned long long	u;

	if (c == 'p')
	{
		u = va_arg(ap, unsigned long long);
		if (u == 0)
			*count += write(1, "(nil)", 5);
		else
		{
			*count += write(1, "0x", 2);
			*count += ft_putnbr_base(u, "0123456789abcdef");
		}
	}
	else if (c == 'x' || c == 'X')
	{
		u = va_arg(ap, unsigned int);
		if (c == 'X')
			*count += ft_putnbr_base(u, "0123456789ABCDEF");
		else
			*count += ft_putnbr_base(u, "0123456789abcdef");
	}
	else if (c == 'u')
		*count += ft_putnbr(va_arg(ap, unsigned int));
	else if (c == '%')
		*count += ft_putchar('%');
}

void	mdt(char c, va_list ap, int *count)
{
	char			*str;
	int				nb;

	if (c == 'c' || c == 'd' || c == 'i')
	{
		nb = va_arg(ap, int);
		if (c == 'c')
			*count += ft_putchar(nb);
		else
		{
			ft_putnbr(nb);
			*count += ft_nblen(nb);
		}
	}
	else if (c == 's')
	{
		str = va_arg(ap, char *);
		*count += ft_putstr(str);
	}
	else
		mdt2(c, ap, count);
}
