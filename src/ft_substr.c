/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:38:18 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/24 19:00:12 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substrlen;
	char	*substr;

	substrlen = min(ft_strlen(s) - start, len);
	substr = malloc(sizeof(char) * (substrlen + 1));
	if (substr)
	{
		(void)len;
	}
	return (substr);
}
