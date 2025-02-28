/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:46:26 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/08 16:08:23 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hashtable.h"
#include "libft.h"

void	hash_table_insert(t_hash_table *ht, void *key)
{
	int	index;

	index = ht->hash_function(key, ht->size);
	ft_lstadd_front(&ht->bins[index], ft_lstnew(key));
}
