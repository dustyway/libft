/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_peek_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:33:23 by pschneid          #+#    #+#             */
/*   Updated: 2025/02/26 14:31:35 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_addendum.h"
#include "queue.h"

void	*queue_peek_n(t_queue *q, size_t n)
{
	if (q == NULL)
		return (NULL);
	return (lst_nth(q->front, n));
}
