/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:05:08 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/30 17:52:05 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static size_t	_count_words(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	wlen;
	int		i;

	tab = (char **)malloc((_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				wlen = ft_strlen(s);
			else
				wlen = ft_strchr(s, c) - s;
			tab[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	tab[i] = NULL;
	return (tab);
}
