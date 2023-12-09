/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:12:56 by smalloir          #+#    #+#             */
/*   Updated: 2022/10/19 14:27:13 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if (*lst)
	{
		copy = ft_lstlast(*lst);
		copy->next = new;
	}
	else
		*lst = new;
}
