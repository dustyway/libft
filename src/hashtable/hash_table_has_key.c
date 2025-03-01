/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_has_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:00:18 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/25 13:00:19 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <hashtable.h>

int	hash_table_has_key(t_hash_table *ht, void *key)
{
	int		index;
	t_list	*l;

	index = ht->hash_function(key, ht->size);
	l = ht->bins[index];
	while (l)
	{
		if (ht->cmp(l->content, key) == 0)
			return (1);
		l = l->next;
	}
	return (0);
}
