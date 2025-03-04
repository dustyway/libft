/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:02:12 by pschneid          #+#    #+#             */
/*   Updated: 2025/03/04 13:49:52 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef QUEUE_H
# define QUEUE_H
# include "libft.h"

typedef struct s_queue
{
	t_list	*front;
	t_list	*back;
	size_t	size;
	void	(*del)(void *);
}			t_queue;

void		init_queue(t_queue **q, void (*del)(void *));
int			queue_is_empty(t_queue *queue);
void		enqueue(t_queue *queue, void *value);
void		*queue_peek(const t_queue *q);
void		*queue_peek_n(t_queue *q, size_t n);
void		*dequeue(t_queue *queue);
void		dequeue_free(t_queue *queue);
size_t		queue_size(const t_queue *q);
void		clear_queue(t_queue **q);

#endif // QUEUE_H
