/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:56:50 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/25 12:56:51 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_addendum.h"
#include "queue.h"

/**
 * @brief initializes a queue
 *
 * @param q pointer to pointer to t_queue
 * @param del function to clean up queue elements (for example free)
 */

void	queue_init(t_queue **q, void (*del)(void *))
{
	*q = safe_malloc(sizeof(t_queue));
	(*q)->front = NULL;
	(*q)->back = NULL;
	(*q)->size = 0;
	(*q)->del = del;
}
