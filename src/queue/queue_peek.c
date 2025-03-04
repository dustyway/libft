/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:32:50 by pschneid          #+#    #+#             */
/*   Updated: 2025/02/26 11:32:57 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"

void	*queue_peek(const t_queue *q)
{
	if (q == NULL || q->front == NULL)
		return (NULL);
	return (q->front->content);
}
