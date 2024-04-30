/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:05:08 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/30 17:25:13 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/* #include <stdio.h> */
#include <stdlib.h>

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, const char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(charset, s[i]))
			i++;
		if (s[i] && !ft_strchr(charset, s[i]))
			count++;
		while (s[i] && !ft_strchr(charset, s[i]))
			i++;
	}
	return (count);
}

static char	*getword(const char *s, int i, const char *charset)
{
	char	*res;
	int		j;
	int		wordlen;

	j = 0;
	wordlen = 0;
	while (s[i + wordlen] && !ft_strchr(charset, s[i + wordlen]))
		wordlen++;
	res = malloc(sizeof(char) * wordlen + 1);
	if (!res)
		return (NULL);
	while (s[i] && !ft_strchr(charset, s[i]))
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(const char *s, const char *charset)
{
	int		i;
	int		wordcount;
	char	**tab;

	tab = ft_calloc(sizeof(char *), (count_words(s, charset) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(charset, s[i]))
			i++;
		if (s[i])
		{
			tab[wordcount] = getword(s, i, charset);
			if (!tab[wordcount])
				return (ft_free_tab(tab), NULL);
			wordcount++;
		}
		while (s[i] && !ft_strchr(charset, s[i]))
			i++;
	}
	tab[wordcount] = 0;
	return (tab);
}

/* int	count_words(const char *str, char c) */
/* { */
/* 	int	nwords; */
/* 	int	i; */

/* 	if (!str || *str == '\0') */
/* 		return (0); */
/* 	if (str[1] == '\0') */
/* 		return (str[0] != c); */
/* 	i = 1; */
/* 	nwords = 0; */
/* 	while (str[i] != 0) */
/* 	{ */
/* 		if (str[i - 1] == c && str[i] != c) */
/* 			nwords++; */
/* 		i++; */
/* 	} */
/* 	if (str[i - 1] != c) */
/* 		nwords++; */
/* 	return (nwords); */
/* } */

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
/* /\* 	tab = ft_split("hello!", ' ');	 *\/ */
/* /\* 	while (tab[i]) *\/ */
/* /\* 	{ *\/ */
/* /\* 		printf("%s\n", tab[i]); *\/ */
/* /\* 		free(tab[i]); *\/ */
/* /\* 		i++; *\/ */
/* /\*  	} *\/ */
/* /\* 	free(tab); *\/ */
/* /\* } *\/ */
