/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:37:19 by pschneid          #+#    #+#             */
/*   Updated: 2025/02/28 16:12:45 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stack.h>
#include <stdlib.h>

void	*pop_stack(t_stack *s)
{
	t_list	*head;
	void	*content;

	if (!s || !s->values)
		return (NULL);
	head = s->values;
	content = head->content;
	s->values = s->values->next;
	ft_lstdelone(head, NULL);
	s->size--;
	return (content);
}
