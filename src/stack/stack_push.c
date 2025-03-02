/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:08:07 by pschneid          #+#    #+#             */
/*   Updated: 2025/02/26 15:51:29 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "libft_addendum.h"
#include "stack.h"

void	stack_push(t_stack *stack, void *value)
{
	t_list	*new_node;

	new_node = ft_lstnew(value);
	if (!new_node)
		error_exit("Error in push_stack: Could not allocate memory\n");
	new_node->next = stack->values;
	stack->values = new_node;
	stack->size++;
}
