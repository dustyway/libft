/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:56:53 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/25 12:56:54 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

/**
 *
 * @param stack
 * @return size of stack
 */
size_t	stack_size(const t_stack *stack)
{
	return (stack->size);
}
