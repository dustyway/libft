/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:41:24 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/30 19:37:56 by pschneid         ###   ########.fr       */
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

/* #include "libft.h" */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*to;
	unsigned char	temp[len];

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	while (i < len)
	{
		*(temp + i) = *(from + i);
		i++;
	}
	while (i--)
		*(to + i) = *(temp + i);
	return (dst);
}
