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
#include <libft_addendum.h>

void	*dequeue_nth(t_queue *queue, size_t n)
{
	void	*value;
	t_list	*prev;
	t_list	*nth;

	if (n == 0)
		return (dequeue(queue));
	if (queue->size < n + 1)
		return (NULL);
	prev = lst_drop(queue->front, n - 1);
	nth = prev->next;
	value = nth->content;
	prev->next = nth->next;
	if (nth == queue->back)
		queue->back = prev;
	ft_lstdelone(nth, NULL);
	queue->size--;
	return (value);
}
