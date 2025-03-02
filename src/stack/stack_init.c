/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:56:50 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/25 12:56:51 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_addendum.h"
#include "stack.h"

/**
 * @brief initializes a stack
 *
 * @param s pointer to pointer to t_stack
 * @param del function to clean up stack elements (for example free)
 */
void stack_init(t_stack	**s, void (*del)(void *))
{
	*s = safe_malloc(sizeof(t_stack));
	(*s)->values = NULL;
	(*s)->size = 0;
	(*s)->del = del;
}
