/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:52:59 by smalloir          #+#    #+#             */
/*   Updated: 2022/10/21 01:32:10 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				j;
	unsigned char	n;

	i = 0;
	j = -1;
	n = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == n)
			j = i;
		i++;
	}
	if (n == 0)
		return ((char *)&s[i]);
	if (j < 0)
		return (0);
	else
		return ((char *)&s[j]);
}
