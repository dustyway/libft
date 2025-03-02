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

void	clear_queue(t_queue **q)
{
	ft_lstclear(&((*q)->front), (*q)->del);
	free(*q);
	*q = NULL;
}
