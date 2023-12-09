/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 05:25:21 by smalloir          #+#    #+#             */
/*   Updated: 2022/11/11 01:25:19 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bonus1(char *fmt, va_list ap, int *count, int i)
{
	int	j;

	j = i;
	if (fmt[j] == '.')
		j++;
	while (fmt[j] >= '0' && fmt[j] <= '9')
		j++;
	if (fmt[i] == '.' && fmt[j] == 'c')
	{
		mdt(fmt[j], ap, count);
		return (j - 1);
	}
	j = i;
	while (fmt[j] == '-')
		j++;
	while (fmt[j] >= '0' && fmt[j] <= '9')
		j++;
	if (fmt[j] == '.' && j != i)
		i = b1_wp(fmt, ap, count, i);
	else if (fmt[i] >= '1' && fmt[i] <= '9')
		i = b1size(fmt, ap, count, i);
	else
		i = b1flags(fmt, ap, count, i);
	return (i - 1);
}

static int	calculate_len3(char *fmt, va_list vl, int i)
{
	int	nb;
	int	len;

	len = -1;
	if (ft_findchar(fmt[i], "di"))
	{
		nb = va_arg(vl, int);
		len = ft_nblen(nb);
	}
	return (len);
}

static int	calculate_len2(char *fmt, va_list vl, int i)
{
	long long	nb;
	int			len;

	len = -1;
	if (fmt[i] == 'p')
	{
		nb = va_arg(vl, unsigned long long);
		if (nb == 0)
			len = 5;
		else
			len = ft_nblenbase(nb, 16) + 2;
	}
	else if (ft_findchar(fmt[i], "uxX"))
	{
		nb = va_arg(vl, unsigned int);
		if (fmt[i] == 'u')
			len = ft_nblen(nb);
		else
			len = ft_nblenbase(nb, 16);
	}
	else
		len = calculate_len3(fmt, vl, i);
	return (len);
}

int	calculate_len(char *fmt, va_list ap, int i)
{
	va_list		vl;
	char		*str;
	int			len;

	len = -1;
	va_copy(vl, ap);
	if (fmt[i] == 'c')
		len = 1;
	else if (fmt[i] == 's')
	{
		str = va_arg(vl, char *);
		if (str == NULL)
			len = 6;
		else
			len = ft_slen(str);
	}
	else
		len = calculate_len2(fmt, vl, i);
	va_end(vl);
	return (len);
}
