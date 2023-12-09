/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:33:33 by smalloir          #+#    #+#             */
/*   Updated: 2022/11/01 15:26:49 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	unsigned long long	len;
	int					i;

	len = ft_slen(base);
	i = ft_nblenbase(nbr, len);
	if (nbr >= len)
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base(nbr % len, base);
	}
	else
		ft_putchar(base[nbr]);
	return (i);
}
