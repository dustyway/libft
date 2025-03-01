/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:54:26 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/07 15:36:26 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hashtable.h"
#include "libft_addendum.h"

t_hash_table	*hash_table_init(int size, int (*hash_function)(void *key,
			int size), int (*cmp)(void *k1, void *k2))
{
	t_hash_table	*ht;
	int				i;

	ht = safe_malloc(sizeof(t_hash_table));
	ht->size = size;
	ht->bins = safe_malloc(size * sizeof(t_list));
	ht->hash_function = hash_function;
	ht->cmp = cmp;
	i = 0;
	while (i < size)
	{
		ht->bins[i] = NULL;
		i++;
	}
	return (ht);
}
