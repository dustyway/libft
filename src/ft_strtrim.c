/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:33:03 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/28 20:03:39 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	slen;
	char	*ret;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	slen = ft_strlen(s1);
	while (slen && ft_strchr(set, s1[slen - 1]))
		slen--;
	ret = malloc(sizeof(char) * (slen + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, slen + 1);
	return (ret);
}
