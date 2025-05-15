/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_drop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:44:37 by pschneid          #+#    #+#             */
/*   Updated: 2025/03/20 22:44:42 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 *
 * @param lst a list
 * @param n an index
 * @return returns the list without the first n elements
 * the memory is not freed
 */
t_list	*lst_drop(t_list *lst, size_t n)
{
	if (!lst)
		return (NULL);
	while (n > 0)
	{
		lst = lst->next;
		if (!lst)
			return (NULL);
		n--;
	}
	return (lst);
}
