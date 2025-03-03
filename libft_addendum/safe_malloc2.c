/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:08:09 by pschneid          #+#    #+#             */
/*   Updated: 2025/01/07 16:20:39 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	*safe_malloc2(size_t bytes, t_list **allocs)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (ptr == NULL)
	{
		ft_putstr_fd("Failed to allocate, aborting...\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_lstadd_front(allocs, ft_lstnew(ptr));
	return (ptr);
}
