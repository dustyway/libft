/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:08:22 by pschneid          #+#    #+#             */
/*   Updated: 2024/12/07 19:07:48 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	lst_del_node(t_list **lst, void *key, void (*del)(void *))
{
	t_list	*temp;
	t_list	*prev;

	temp = *lst;
	if (temp != NULL && temp->content == key)
	{
		*lst = temp->next;
		ft_lstdelone(temp, del);
		return ;
	}
	while (temp != NULL && temp->content != key)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	ft_lstdelone(temp, del);
}
