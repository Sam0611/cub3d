/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b1flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:04:14 by smalloir          #+#    #+#             */
/*   Updated: 2022/11/17 17:49:56 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	b1dot_s(char *fmt, va_list ap, int *count, int i)
{
	int			n;
	int			j;
	char		*str;

	j = 0;
	i++;
	n = ft_atoi(fmt + i);
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	str = va_arg(ap, char *);
	if (str != NULL)
	{
		while (str[j] && j < n)
		{
			*count += write(1, &str[j], 1);
			j++;
		}
	}
	else if (n >= 6)
		*count += write(1, "(null)", 6);
	return (i);
}

static int	b1minus(char *fmt, va_list ap, int *count, int i)
{
	int			n;
	int			len;

	while (fmt[i] == fmt[i + 1])
		i++;
	i++;
	n = ft_atoi(fmt + i);
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	len = calculate_len(fmt, ap, i);
	if (len < 0)
		return (i);
	mdt(fmt[i], ap, count);
	while (n > len)
	{
		*count += write(1, " ", 1);
		n--;
	}
	return (i);
}

static int	b1zero_cs(char *fmt, va_list ap, int *count, int i)
{
	int			n;
	int			len;

	i++;
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

int	b1flags(char *fmt, va_list ap, int *count, int i)
{
	int	j;

	j = i + 1;
	while (fmt[j] >= '0' && fmt[j] <= '9')
		j++;
	if (fmt[i] == '-')
		i = b1minus(fmt, ap, count, i);
	else if (fmt[i] == '.' && fmt[j] == 's')
		i = b1dot_s(fmt, ap, count, i);
	else if (fmt[i] == '0' && ft_findchar(fmt[j], "cs"))
		i = b1zero_cs(fmt, ap, count, i);
	else if (ft_findchar(fmt[i], ".0") && ft_findchar(fmt[j], "di"))
		i = b1dz_di(fmt, ap, count, i);
	else if (fmt[i] == '.' && fmt[j] == 'p')
		i = b1d_p(fmt, ap, count, i);
	else if (fmt[i] == '0' && fmt[j] == 'p')
		i = b1z_p(fmt, ap, count, i);
	else if (ft_findchar(fmt[i], ".0") && ft_findchar(fmt[j], "uxX"))
		i = b1dz_ux(fmt, ap, count, i);
	return (i);
}
