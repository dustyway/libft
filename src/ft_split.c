/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:05:08 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/30 17:40:49 by pschneid         ###   ########.fr       */
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
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

/* void	next_word(const char *str, char c, int *start, int *end) */
/* { */
/* 	*start = *end; */
/* 	while (str[*start] && str[*start] == c) */
/* 		(*start)++; */
/* 	*end = *start; */
/* 	while (str[*end] && str[*end] != c) */
/* 		(*end)++; */
/* } */

/* char	**ft_split(char const *s, char c) */
/* { */
/* 	int		nwords; */
/* 	int		start; */
/* 	int		end; */
/* 	char	**tab; */
/* 	int i; */

/* 	i=0; */
/* 	nwords = count_words(s, c); */
/* 	/\* printf("nwords: %\n", nwords); *\/ */
/* 	tab = (char **)malloc(sizeof(char *) * (nwords + 1)); */
/* 	if (!tab) */
/* 		return (NULL); */

/* 	end = 0; */
/* 	next_word(s, c, &start, &end); */
/* 	while (start != end) */
/* 	{ */
/* 		tab[i] = malloc(sizeof(char) * ((end - start) + 1)); */
/* 		if (!tab[i]) */
/* 			return (NULL); */
/* 		ft_strlcpy(tab[i], s + start, (end - start) + 1); */
/* 		next_word(s, c, &start, &end); */
/* 		i++; */
/* 	} */
/* 	tab[i]=NULL; */
/* 	return (tab); */
/* } */

/* /\* int main() *\/ */
/* /\* { *\/ */
/* /\* 	char **tab; *\/ */
/* /\* 	int i; *\/ */
/* /\* 	i =0; *\/ */
/* /\* 	/\\* tab = ft_split("hello!zzzzzz", 'z'); *\\/ *\/ */
/* /\* 	/\\* tab = ft_split("a b c", ' '); *\\/ *\/ */
/* /\* 	tab = ft_split("hello!", ' ');		*\/ */
/* /\* 	while (tab[i]) *\/ */
/* /\* 	{ *\/ */
/* /\* 		printf("%s\n", tab[i]); *\/ */
/* /\* 		free(tab[i]); *\/ */
/* /\* 		i++; *\/ */
/* /\*  	} *\/ */
/* /\* 	free(tab); *\/ */
/* /\* } *\/ */
