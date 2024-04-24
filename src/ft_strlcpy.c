/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:55:06 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:47 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	const char	*osrc = src;
	size_t		nleft;

	nleft = dsize;
	if (nleft != 0)
	{
		while (--nleft != 0)
		{
			if ((*dst++ = *src++) == '\0')
				break ;
		}
	}
	if (nleft == 0)
	{
		if (dsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}

/* static int	min(int a, int b) */
/* { */
/* 	if (a < b) */
/* 		return (a); */
/* 	return (b); */
/* } */

/* size_t	ft_strlcpy(char *dst, const char *src, size_t size) */
/* { */
/* 	size_t	n; */
/* 	size_t	slen; */

/* 	slen = ft_strlen(src); */
/* 	if (size) */
/* 	{ */
/* 		n = min(slen, size - 1); */
/* 		if (n) */
/* 			ft_memcpy(dst, src, n); */
/* 		dst[n] = '\0'; */
/* 	} */
/* 	return (slen); */
/* } */

/* size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize) */
/* { */
/* 	size_t	src_len; */

/* 	src_len = ft_strlen(src); */
/* 	if (src_len + 1 < dstsize) */
/* 		ft_memcpy(dst, src, src_len + 1); */
/* 	else if (dstsize != 0) */
/* 	{ */
/* 		ft_memcpy(dst, src, dstsize - 1); */
/* 		dst[dstsize - 1] = 0; */
/* 	} */
/* 	return (src_len); */
/* } */
