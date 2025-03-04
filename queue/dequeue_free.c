/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:48:19 by pschneid          #+#    #+#             */
/*   Updated: 2025/03/04 13:49:23 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"
#include <libft.h>

void	dequeue_free(t_queue *queue)
{
	void	*value;
	t_list	*head;

	if (queue->front == NULL)
		return (NULL);
	head = queue->front;
	value = head->content;
	queue->front = queue->front->next;
	ft_lstdelone(head, queue->del);
	if (queue->front == NULL)
		queue->back = NULL;
	queue->size--;
	return ;
}
