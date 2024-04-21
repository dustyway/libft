/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:41:49 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/21 19:50:57 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* char *ft_strnstr(const char *s, const char *find, size_t slen) */
/* { */
/* 	char c, sc; */
/* 	size_t len; */

/* 	if ((c = *find++) != '\0') { */
/* 		len = ft_strlen(find); */
/* 		do { */
/* 			do { */
/* 				if (slen-- < 1 || (sc = *s++) == '\0') */
/* 					return (NULL); */
/* 			} while (sc != c); */
/* 			if (len > slen) */
/* 				return (NULL); */
/* 		} while (strncmp(s, find, len) != 0); */
/* 		s--; */
/* 	} */
/* 	return ((char *)s); */
/* } */

/* char	*ft_strstr(char *str, char *to_find) */
/* { */
/* 	char	*a; */
/* 	char	*b; */

/* 	b = to_find; */
/* 	if (*b == 0) */
/* 		return (str); */
/* 	while (*str != 0) */
/* 	{ */
/* 		if (*str == *b) */
/* 		{ */
/* 			a = str; */
/* 			while (*a == *b && *b != 0) */
/* 			{ */
/* 				a++; */
/* 				b++; */
/* 			} */
/* 			if (*b == 0) */
/* 				return (str); */
/* 		} */
/* 		b = to_find; */
/* 		str++; */
/* 	} */
/* 	return (NULL); */
/* } */
