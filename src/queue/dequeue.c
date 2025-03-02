/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:56:34 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/25 12:56:35 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"
#include <libft.h>

void	*dequeue(t_queue *queue)
{
	void	*value;
	t_list	*head;

	if (queue->front == NULL)
		return (NULL);
	head = queue->front;
	value = head->content;
	queue->front = queue->front->next;
	ft_lstdelone(head, NULL);
	if (queue->front == NULL)
		queue->back = NULL;
	queue->size--;
	return (value);
}
