/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:41:24 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/30 18:04:41 by pschneid         ###   ########.fr       */
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

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    char    *c_src;
    char    *c_dst;
    size_t    i;
    
    if (!dst && !src)
        return (NULL);
    c_src = (char *) src;
    c_dst = (char *) dst;
    i = 0;
    if (c_dst > c_src)
        while (len-- > 0)
            c_dst[len] = c_src[len];
    else
    {
        while (i++ < len)
            c_dst[i] = c_src[i];
    }
    return (dst);
}
