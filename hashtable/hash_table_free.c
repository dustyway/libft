/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:50:11 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/07 16:20:40 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hashtable.h"
#include <stdlib.h>

void	hash_table_free(t_hash_table *ht)
{
	int	i;

	i = 0;
	while (i < ht->size)
	{
		ft_lstclear(&ht->bins[i++], NULL);
	}
	free(ht->bins);
	free(ht);
}
