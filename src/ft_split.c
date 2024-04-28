/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:05:08 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/28 21:17:42 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char **ft_split(char const *s, char c)
{
	(void)s;
	(void)c;
	return NULL;
}




/* typedef struct s_point */
/* { */
/* 	int	start; */
/* 	int	end; */
/* }		t_point; */


/* t_point	next_word(char *str, char *charset, int offset) */
/* { */
/* 	t_point	nxtw; */

/* 	while (str[offset] && char_in_str(str[offset], charset)) */
/* 		offset++; */
/* 	nxtw.start = offset; */
/* 	while (str[offset] && !char_in_str(str[offset], charset)) */
/* 		offset++; */
/* 	nxtw.end = offset; */
/* 	return (nxtw); */
/* } */

/* int	nr_words(char *str, char *charset) */
/* { */
/* 	int	nwords; */
/* 	int	i; */

/* 	if (!str || *str == '\0') */
/* 		return (0); */
/* 	if (str[1] == '\0') */
/* 		return (!char_in_str(str[0], charset)); */
/* 	i = 1; */
/* 	nwords = 0; */
/* 	while (str[i] != 0) */
/* 	{ */
/* 		if (char_in_str(str[i - 1], charset) && !char_in_str(str[i], charset)) */
/* 			nwords++; */
/* 		i++; */
/* 	} */
/* 	if (!char_in_str(str[i - 1], charset)) */
/* 		nwords++; */
/* 	return (nwords); */
/* } */

/* void	strcpypart(char *dest, char *str, int start, int end) */
/* { */
/* 	int	i; */

/* 	i = 0; */
/* 	while (i < end - start) */
/* 	{ */
/* 		dest[i] = str[start + i]; */
/* 		i++; */
/* 	} */
/* 	dest[i] = 0; */
/* } */

/* char	**ft_split(char *str, char *charset) */
/* { */
/* 	char	**ret; */
/* 	t_point	nxtw; */
/* 	int		nwords; */
/* 	int		i; */

/* 	nwords = nr_words(str, charset); */
/* 	ret = (char **)malloc(sizeof(char *) * (nwords + 1)); */
/* 	if (!ret) */
/* 		return (NULL); */
/* 	i = 0; */
/* 	nxtw = next_word(str, charset, 0); */
/* 	while (nxtw.start != nxtw.end) */
/* 	{ */
/* 		ret[i] = (char *)malloc(sizeof(char) * ((nxtw.end - nxtw.start) + 1)); */
/* 		if (!ret[i]) */
/* 			return (NULL); */
/* 		strcpypart(ret[i], str, nxtw.start, nxtw.end); */
/* 		nxtw = next_word(str, charset, nxtw.end); */
/* 		i++; */
/* 	} */
/* 	ret[i] = 0; */
/* 	return (ret); */
/* } */
