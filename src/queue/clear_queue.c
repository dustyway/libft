/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:56:25 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/25 12:56:27 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"
#include <stdlib.h>

void	clear_queue(t_queue *queue)
{
	ft_lstclear(&(queue->front), queue->del);
	free(queue);
}
