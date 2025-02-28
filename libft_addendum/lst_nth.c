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

void	*lst_nth(t_list *lst, size_t n)
{
	if (!lst || n < 1)
		return (NULL);
	while (n > 1)
	{
		lst = lst->next;
		if (!lst)
			return (NULL);
		n--;
	}
	return (lst->content);
}
