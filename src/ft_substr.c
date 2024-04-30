/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:38:18 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/30 16:23:51 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

/* static char *_empty_string() */
/* { */
/* 	char *s; */
/* 	s = malloc(sizeof(char)); */
/* 	if (!s) */
/* 		return (NULL); */
/* 	s[0] = '\0'; */
/* 	return (s); */
/* } */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	substrlen;
	char	*substr;

	slen = ft_strlen(s);
	if (start >= slen)
		substrlen = 0;
	else
		substrlen = min(slen - start, len);
	substr = malloc(sizeof(char) * (substrlen + 1));
	if (!substr)
		return (NULL);
	substr[substrlen] = '\0';
	if (substrlen)
		ft_strlcpy(substr, s + start, substrlen + 1);
	return (substr);
}

int	main(void)
{
	printf("%s\n", ft_substr("", 1, 1));
}
