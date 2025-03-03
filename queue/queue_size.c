/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:34:05 by pschneid          #+#    #+#             */
/*   Updated: 2025/03/02 09:34:13 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"

/**
 * @brief returns the size of the stack
 * @param stack
 * @return size of stack
 */
size_t	queue_size(const t_queue *q)
{
	return (q->size);
}
