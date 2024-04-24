/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:24:35 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/21 18:36:06 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	uc = c;
	const unsigned char	*su = s;

	while (n > 0)
	{
		if (*su == uc)
			return ((void *)su);
		su++;
		n--;
	}
	return (NULL);
}
