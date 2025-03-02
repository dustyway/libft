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

void stack_init(t_stack	**s, void (*del)(void *));
size_t		stack_size(const t_stack *stack);
void		stack_push(t_stack *stack, void *value);
void		*stack_pop(t_stack *stack);
void		*stack_peek(t_stack *stack);
void		clear_stack(t_stack **stack);
int         stack_is_empty(t_stack *stack);

#endif // STACK_H
