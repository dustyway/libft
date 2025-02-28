/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:56:40 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/25 12:56:45 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"
#include <libft.h>

void	enqueue(t_queue *queue, void *value)
{
	t_list	*new_node;

	new_node = ft_lstnew(value);
	if (queue->back == NULL)
	{
		queue->front = new_node;
		queue->back = new_node;
	}
	else
	{
		queue->back->next = new_node;
		queue->back = new_node;
	}
}
