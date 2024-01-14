/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsearch_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:13:28 by smalloir          #+#    #+#             */
/*   Updated: 2023/12/12 14:13:30 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strsearch_chars(const char *s, char *c)
{
	int				i;
	int				j;

	i = 0;
	while (s[i])
    {
        j = 0;
        while (c[j])
        {
            if (c[j] == s[i])
                return (i);
            j++;
        }
        i++;
    }
	return (i);
}
