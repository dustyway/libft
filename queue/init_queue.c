/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:56:50 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/25 12:56:51 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_addendum.h"
#include "queue.h"

t_queue	*init_queue(void (*del)(void *))
{
	t_queue	*q;

	q = safe_malloc(sizeof(t_queue));
	q->front = NULL;
	q->back = NULL;
	q->del = del;
	return (q);
}
