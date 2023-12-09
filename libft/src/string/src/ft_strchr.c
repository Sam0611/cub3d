/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:51:28 by smalloir          #+#    #+#             */
/*   Updated: 2022/10/21 01:25:26 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	n;

	i = 0;
	n = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == n)
			return ((char *)&s[i]);
		i++;
	}
	if (n == 0)
		return ((char *)&s[i]);
	return (0);
}
