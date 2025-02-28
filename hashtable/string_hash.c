/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:30:42 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/06 16:04:29 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stddef.h"
#define CONST 257

int	string_hash(void *k, int size)
{
	long	total;
	char	*key;

	key = k;
	total = 0;
	if (key == NULL)
		return (total);
	while (*key)
	{
		total = (CONST * total + (int)*key) % size;
		key++;
	}
	return (total);
}
