/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:47:52 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/08 12:06:22 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "libft.h"

typedef struct s_hash_table
{
	int			size;
	t_list		**bins;
	int			(*hash_function)(void *key, int size);
	int			(*cmp)(void *k1, void *k2);
}				t_hash_table;

t_hash_table	*hash_table_init(int size, int (*hash_function)(void *key,
						int size), int (*cmp)(void *k1, void *k2));
void			hash_table_insert(t_hash_table *ht, void *key);
void			hash_table_free(t_hash_table *ht);
int				hash_table_has_key(t_hash_table *ht, void *key);
int				string_hash(void *key, int size);
#endif
