/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:41:59 by smalloir          #+#    #+#             */
/*   Updated: 2022/10/19 14:18:33 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*copy;

	if (!del || !lst)
		return ;
	while (*lst && del)
	{
		copy = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = copy;
	}
	*lst = 0;
}
