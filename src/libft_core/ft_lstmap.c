/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:41:22 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/30 20:08:11 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newl;

	if (!lst || !f || !del)
		return (NULL);
	newl = ft_lstnew(f(lst->content));
	if (newl == NULL)
	{
		ft_lstclear(&newl, del);
		return (NULL);
	}
	newl->next = ft_lstmap(lst->next, f, del);
	return (newl);
}
