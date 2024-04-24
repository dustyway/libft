/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:03:50 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/23 16:58:31 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	const char	*odst = dst;
	const char	*osrc = src;
	size_t		n;
	size_t		dlen;

	n = dsize;
	/* Find the end of dst and adjust bytes left but don't go past end. */
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dsize - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc)); /* count does not include NUL */
}

/* size_t	ft_strlcat(char *dst, const char *src, size_t size) */
/* { */
/* 	size_t	dlen; */

/* 	dlen = ft_strlen(dst); */
/* 	if (dlen < size - 1) */
/* 		return (dlen + ft_strlcpy(dst + dlen, src, size - dlen)); */
/* 	else */
/* 		return (dlen + ft_strlen(src)); */
/* } */

/* size_t	ft_strlcat(char *dst, const char *src, size_t dstsize) */
/* { */
/* 	size_t	src_len; */
/* 	size_t	cur; */

/* 	src_len = ft_strlen(dst); */
/* 	cur = 0; */
/* 	if (dstsize <= src_len) */
/* 		return (ft_strlen(src) + dstsize); */
/* 	while (src[cur] && (src_len + cur) < (dstsize - 1)) */
/* 	{ */
/* 		dst[src_len + cur] = src[cur]; */
/* 		cur++; */
/* 	} */
/* 	dst[src_len + cur] = 0; */
/* 	return (ft_strlen(src) + src_len); */
/* } */
