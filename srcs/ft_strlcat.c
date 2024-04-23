/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:03:50 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/23 15:03:52 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;

	dlen = ft_strlen(dst);
	if (dlen < size - 1)
		return (dlen + ft_strlcpy(dst + dlen, src, size - dlen));
	else
		return (dlen + ft_strlen(src));
}
