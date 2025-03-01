/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:02:12 by pschneid          #+#    #+#             */
/*   Updated: 2025/02/26 18:27:16 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STACK_H
# define STACK_H
# include "libft.h"

typedef struct s_stack
{
	t_list	*values;
	size_t	size;
	void	(*del)(void *);
}			t_stack;

t_stack		*init_stack(void (*del)(void *));
size_t		stack_size(const t_stack *stack);
void		push_stack(t_stack *stack, void *value);
void		*pop_stack(t_stack *stack);
void		*peek_stack(t_stack *stack);
void		clear_stack(t_stack *stack);

#endif // STACK_H
