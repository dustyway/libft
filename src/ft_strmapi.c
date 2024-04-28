/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:49:10 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/28 17:18:56 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	slen;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	dest = malloc(sizeof(char) * (slen + 1));
	if (!dest)
		return (NULL);
	while (i < slen)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[slen] = '\0';
	return (dest);
}
