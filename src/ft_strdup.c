/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:17:11 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/28 17:19:25 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		siz;
	char	*dest;

	siz = ft_strlen(src)+1;
	dest = (char *)malloc(sizeof(char) * siz);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, siz);
	return (dest);
}
