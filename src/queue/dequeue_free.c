/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:52:51 by pschneid          #+#    #+#             */
/*   Updated: 2025/03/04 17:36:00 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"
#include <libft.h>

void	dequeue_free(t_queue *queue)
{
	t_list	*head;

	if (queue->front == NULL)
		return ;
	head = queue->front;
	queue->front = queue->front->next;
	ft_lstdelone(head, queue->del);
	if (queue->front == NULL)
		queue->back = NULL;
	queue->size--;
	return ;
}
