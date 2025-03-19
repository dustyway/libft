/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_nth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:41:27 by pschneid          #+#    #+#             */
/*   Updated: 2025/03/19 15:54:21 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"
#include <libft.h>

void	*dequeue_nth(t_queue *queue, size_t n)
{
	void	*value;
	t_list	*iter;
	t_list	*prev;
	int i;

	if (queue->size < n+1)
		return (NULL);
	iter = queue->front;
	prev = NULL;
	i = 0;
	while(i<n)
	{
	    prev = iter;
	    iter = iter->next;
	    i++;
	}

	value = iter->content;
	if (prev == NULL)
	    queue->front = iter->next;
	else
	    prev->next = iter->next;
	ft_lstdelone(iter, NULL);
	if (queue->front == NULL)
		queue->back = NULL;
	queue->size--;
	return (value);
}
