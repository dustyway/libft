/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:41:24 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/30 17:53:54 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* void	*ft_memmove(void *dest, const void *src, size_t n) */
/* { */
/* 	char		*d; */
/* 	const char	*s = src; */

/* 	d = dest; */
/* 	if (d < s) */
/* 		while (n--) */
/* 			*d++ = *s++; */
/* 	else if (d > s) */
/* 	{ */
/* 		d += n; */
/* 		s += n; */
/* 		while (n--) */
/* 			*--d = *--s; */
/* 	} */
/* 	return (dest); */
/* } */

static	void	*ft_revmemcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest || !src)
		return (0);
	d = dest + n - 1;
	s = src + n - 1;
	while (n-- > 0)
		*d-- = *s--;
	return (d);
}

void	*ft_memmove(void *dest, const void*src, size_t n)
{
	if (!dest || !src)
		return (0);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
		ft_revmemcpy(dest, src, n);
	return (dest);
}
