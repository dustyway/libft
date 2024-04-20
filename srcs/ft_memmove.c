/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:41:24 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/20 17:39:09 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (s < d && d < s + n)
	{
		d += n;
		s += n;
		while (n)
		{
			*--d = *--s;
			n--;
		}
	}
	else
	{
		while (n)
		{
			*d++ = *s++;
			n--;
		}
	}
	return (dest);
}
