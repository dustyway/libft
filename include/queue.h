/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:02:12 by pschneid          #+#    #+#             */
/*   Updated: 2025/02/26 14:30:50 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef QUEUE_H
# define QUEUE_H
# include "libft.h"

typedef struct s_queue
{
	t_list	*front;
	t_list	*back;
	void	(*del)(void *);
}			t_queue;

t_queue		*init_queue(void (*del)(void *));
int			is_empty(t_queue *queue);
void		enqueue(t_queue *queue, void *value);
void		*queue_peek(const t_queue *q);
void		*queue_peek_n(t_queue *q, size_t n);
void		*dequeue(t_queue *queue);
void		clear_queue(t_queue *queue);

#endif // QUEUE_H
