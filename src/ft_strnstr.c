/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:41:49 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/26 16:03:34 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	flen;

	flen = ft_strlen(find);
	if (flen == 0)
		return ((char *)s);
	while (*s && flen <= slen)
	{
		if ((*s == *find) && (0 == ft_strncmp(s, find, flen)))
			return ((char *)s);
		s++;
		slen--;
	}
	return (NULL);
}
