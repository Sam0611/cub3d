/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:07:37 by smalloir          #+#    #+#             */
/*   Updated: 2022/10/19 14:26:16 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check(const char *str)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	sign = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	j = i;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-2);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if ((i - j) > 18)
	{
		if (str[sign] == '-')
			return (-2);
		else
			return (-1);
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	nbr;

	i = ft_check(nptr);
	sign = 1;
	nbr = 0;
	if (i == -2)
		return (0);
	if (i == -1)
		return (i);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}
