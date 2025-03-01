/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:29:49 by pschneid          #+#    #+#             */
/*   Updated: 2025/02/26 17:58:22 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include <stdlib.h>

void	clear_stack(t_stack *s)
{
	ft_lstclear(&s->values, s->del);
	free(s);
}
