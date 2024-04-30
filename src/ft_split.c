/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:05:08 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/30 17:20:41 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/* #include <stdio.h> */
#include <stdlib.h>

int	count_words(const char *str, char c)
{
	int	nwords;
	int	i;

	if (!str || *str == '\0')
		return (0);
	if (str[1] == '\0')
		return (str[0] != c);
	i = 1;
	nwords = 0;
	while (str[i] != 0)
	{
		if (str[i - 1] == c && str[i] != c)
			nwords++;
		i++;
	}
	if (str[i - 1] != c)
		nwords++;
	return (nwords);
}

void	next_word(const char *str, char c, int *start, int *end)
{
	*start = *end;
	while (str[*start] && str[*start] == c)
		(*start)++;
	*end = *start;
	while (str[*end] && str[*end] != c)
		(*end)++;
}

char	**ft_split(char const *s, char c)
{
	int		nwords;
	int		start;
	int		end;
	char	**tab;
	int i;

	i=0;
	nwords = count_words(s, c);
	/* printf("nwords: %\n", nwords); */
	tab = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (!tab)
		return (NULL);

	end = 0;
	next_word(s, c, &start, &end);
	while (start != end)
	{
		tab[i] = malloc(sizeof(char) * ((end - start) + 1));
		if (!tab[i])
			return (NULL);
		ft_strlcpy(tab[i], s + start, (end - start) + 1);
		next_word(s, c, &start, &end);
		i++;
	}
	tab[i]=NULL;
	return (tab);
}

/* int main() */
/* { */
/* 	char **tab; */
/* 	int i; */
/* 	i =0; */
/* 	/\* tab = ft_split("hello!zzzzzz", 'z'); *\/ */
/* 	/\* tab = ft_split("a b c", ' '); *\/ */
/* 	tab = ft_split("hello!", ' ');	 */
/* 	while (tab[i]) */
/* 	{ */
/* 		printf("%s\n", tab[i]); */
/* 		free(tab[i]); */
/* 		i++; */
/*  	} */
/* 	free(tab); */
/* } */
