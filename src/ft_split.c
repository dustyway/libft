/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:05:08 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/30 17:09:29 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
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
	char	**tab_iter;

	nwords = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (!tab)
		return (NULL);
	tab_iter = tab;
	end = 0;
	next_word(s, c, &start, &end);
	while (start != end)
	{
		*tab_iter = malloc(sizeof(char) * ((end - start) + 1));
		if (!*tab_iter)
			return (NULL);
		ft_strlcpy(*tab_iter, s + start, (end - start) + 1);
		next_word(s, c, &start, &end);
		tab_iter++;
	}
	*tab_iter = NULL;
	return (tab);
}

/* int main() */
/* { */
/* 	char **tab; */
/* 	int i; */

/* 	i=0; */
/* 	tab = ft_split("hello!zzzzzz", 'z'); */
/* 	/\* tab = ft_split("a b c", ' ');		*\/ */
/* 	while (tab[i]) */
/* 	{ */
/* 		printf("%s\n", tab[i]); */
/* 		free(tab[i]); */
/* 		i++; */
/*  	} */
/* 	free(tab); */
/* } */
