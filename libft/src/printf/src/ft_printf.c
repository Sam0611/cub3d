/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:55:05 by smalloir          #+#    #+#             */
/*   Updated: 2022/11/09 23:52:58 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	bs(va_list ap, int *count, int n)
{
	char	*str;

	str = va_arg(ap, char *);
	while (n > ft_slen(str))
	{
		*count += write(1, " ", 1);
		n--;
	}
	*count += ft_putstr(str);
}

static int	bonus(char *fmt, va_list ap, int *count, int i)
{
	int	j;
	int	n;

	while ((fmt[i] == ' ' && fmt[i + 1] == ' ')
		|| (fmt[i] == '+' && fmt[i + 1] == '+'))
		i++;
	j = i + 1;
	n = ft_atoi(fmt + j);
	while (fmt[j] >= '0' && fmt[j] <= '9')
		j++;
	if (fmt[j] == 's' && (fmt[i] == ' ' || fmt[i] == '+'))
	{
		bs(ap, count, n);
		i = j - 1;
	}
	else if (ft_findchar(fmt[i], "+ #"))
		bonus2(fmt, ap, count, i);
	else
		i = bonus1(fmt, ap, count, i);
	i++;
	return (i);
}

static int	ft_printf2(char *fmt, va_list ap, int *count, int i)
{
	int	j;

	j = i;
	while (ft_findchar(fmt[j], "+-"))
		j++;
	while (fmt[j] >= '0' && fmt[j] <= '9')
		j++;
	if (fmt[j] == '%')
	{
		*count += write(1, "%", 1);
		return (j);
	}
	if (ft_findchar(fmt[i], "cspdiuxX%"))
		mdt(fmt[i], ap, count);
	else if (ft_findchar(fmt[i], "-0.+# 123456789"))
		i = bonus(fmt, ap, count, i);
	else
	{
		*count += write(1, "%", 1);
		*count += write(1, &fmt[i], 1);
	}
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && !fmt[i + 1])
			return (-1);
		else if (fmt[i] == '%')
			i = ft_printf2((char *)fmt, ap, &count, i + 1);
		else
			count += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
