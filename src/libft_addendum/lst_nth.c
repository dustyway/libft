/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:48:59 by pschneid          #+#    #+#             */
/*   Updated: 2025/02/26 18:27:17 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 *
 * @param lst a list
 * @param n an index
 * @return returns the nth element of the list from the front starting from 0
 */
void	*lst_nth(t_list *lst, size_t n)
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
	return (lst->content);
}
