/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:03:50 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/26 13:00:59 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* If strlcat() traverses size characters without finding a NUL, the length of 
   the string is considered to be size and the destination string will not be 
   NUL-terminated (since there was no space for the NUL).
   This keeps strlcat() from running off the end of a string. In practice this
   should not happen (as it means that either size is incorrect or that dst is 
   not a proper ''C'' string). The check exists to prevent potential security 
   problems in incorrect code. */

static size_t	_strllen(const char *s, size_t size)
{
	size_t	len;

	len = 0;
	while (s[len] && size--)
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;

	dlen = _strllen(dst, size);
	if (dlen <= size)
		return (dlen + ft_strlcpy(dst + dlen, src, size - dlen));
	else
		return (dlen + ft_strlen(src));
}
