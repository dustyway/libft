/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:37:19 by pschneid          #+#    #+#             */
/*   Updated: 2025/02/26 15:50:50 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stack.h>

void	*stack_peek(t_stack *s)
{
	if (!s || !s->values)
		return (NULL);
	return (s->values->content);
}
