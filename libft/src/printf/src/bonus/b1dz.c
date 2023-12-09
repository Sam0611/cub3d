/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b1dz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:52:41 by smalloir          #+#    #+#             */
/*   Updated: 2022/11/18 23:01:09 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	b1dz_neg(char *fmt, int *count, int len, va_list ap)
{
	int	n;
	int	nb;

	n = ft_atoi(fmt + 1);
	nb = va_arg(ap, int);
	write(1, "-", 1);
	while (n > len)
	{
		*count += write(1, "0", 1);
		n--;
	}
	if (*fmt == '.' && n == len)
		*count += write(1, "0", 1);
	*count += ft_nblen(nb);
	if (nb == -2147483648)
		ft_putnbr(2147483648);
	else
	{
		nb *= -1;
		ft_putnbr(nb);
	}
}

int	b1dz_di(char *fmt, va_list ap, int *count, int i)
{
	int		tab[3];
	int		nb;
	va_list	vl;

	tab[0] = i;
	va_copy(vl, ap);
	nb = va_arg(vl, int);
	i++;
	tab[1] = ft_atoi(fmt + i);
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	tab[2] = calculate_len(fmt, ap, i);
	if (nb < 0)
		b1dz_neg(fmt + tab[0], count, tab[2], ap);
	else if (nb || tab[1])
	{
		while (--tab[1] >= tab[2])
			*count += write(1, "0", 1);
		mdt(fmt[i], ap, count);
	}
	else
		nb = va_arg(ap, int);
	va_end(vl);
	return (i);
}

int	b1z_p(char *fmt, va_list ap, int *count, int i)
{
	int					n;
	unsigned long long	nb;
	int					len;

	i++;
	n = ft_atoi(fmt + i);
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	len = calculate_len(fmt, ap, i);
	nb = va_arg(ap, unsigned long long);
	if (nb == 0)
	{
		while (--n >= len)
			*count += write(1, " ", 1);
		*count += write(1, "(nil)", 5);
	}
	else
	{
		*count += write(1, "0x", 2);
		while (--n >= len)
			*count += write(1, "0", 1);
		*count += ft_putnbr_base(nb, "0123456789abcdef");
	}
	return (i);
}

int	b1d_p(char *fmt, va_list ap, int *count, int i)
{
	int					n;
	unsigned long long	nb;
	int					len;

	i++;
	n = ft_atoi(fmt + i);
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	len = calculate_len(fmt, ap, i);
	nb = va_arg(ap, unsigned long long);
	if (nb == 0)
		*count += write(1, "(nil)", 5);
	else
	{
		*count += write(1, "0x", 2);
		while (n > len - 2)
		{
			*count += write(1, "0", 1);
			n--;
		}
		*count += ft_putnbr_base(nb, "0123456789abcdef");
	}
	return (i);
}

int	b1dz_ux(char *fmt, va_list ap, int *count, int i)
{
	int					n;
	int					len;
	unsigned int		nb;
	va_list				vl;

	va_copy(vl, ap);
	nb = va_arg(vl, unsigned int);
	i++;
	n = ft_atoi(fmt + i);
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	if (!nb && !n)
	{
		nb = va_arg(ap, unsigned int);
		return (i);
	}
	len = calculate_len(fmt, ap, i);
	while (n > len)
	{
		*count += write(1, "0", 1);
		n--;
	}
	mdt(fmt[i], ap, count);
	va_end(vl);
	return (i);
}
